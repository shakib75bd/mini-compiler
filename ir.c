#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "ir.h"

static int temp_counter = 0;
static int label_counter = 0;

// Fix create_temp_var and create_label functions:

char* create_temp_var() {
    char *name = malloc(16);
    if (!name) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    sprintf(name, "t%d", temp_counter++);
    return name;
}

char* create_label() {
    char *name = malloc(16);
    if (!name) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    sprintf(name, "L%d", label_counter++);
    return name;
}

// Fix create_ir_node function:
IRNode* create_ir_node(IROpType op, char *dest, char *src1, char *src2) {
    IRNode *node = malloc(sizeof(IRNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    node->op = op;
    node->dest = dest ? strdup(dest) : NULL;
    node->src1 = src1 ? strdup(src1) : NULL;
    node->src2 = src2 ? strdup(src2) : NULL;
    node->labelNum = -1;
    node->next = NULL;
    return node;
}

// Append an IR node to a list
IRNode* append_ir_node(IRNode *head, IRNode *node) {
    if (!head) return node;
    
    IRNode *current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = node;
    return head;
}

// Generate IR from AST
IRNode* generate_ir(ASTNode *ast) {
    if (!ast) return NULL;
    
    IRNode *code = NULL;
    char *temp;
    
    switch (ast->type) {
        case NODE_INT: {
            temp = create_temp_var();
            if (!temp) {
                fprintf(stderr, "Memory allocation failed\n");
                return NULL;
            }
            
            // Allocate memory for the integer value
            char value[32]; // Large enough for any integer
            sprintf(value, "%d", ast->data.int_val);
            
            code = create_ir_node(IR_ASSIGN, temp, value, NULL);
            return code;
        }
            
        case NODE_BINOP: {
            // Generate code for left operand
            IRNode *left_code = generate_ir(ast->data.bin_op.left);
            if (!left_code) return NULL;
            
            // Generate code for right operand
            IRNode *right_code = generate_ir(ast->data.bin_op.right);
            if (!right_code) return NULL;
            
            // Combine the code
            code = left_code;
            IRNode *last = code;
            while (last->next) last = last->next;
            last->next = right_code;
            
            // Create the operation node
            temp = create_temp_var();
            if (!temp) return NULL;
            
            IROpType op_type;
            
            switch (ast->data.bin_op.op) {
                case OP_ADD: op_type = IR_ADD; break;
                case OP_SUB: op_type = IR_SUB; break;
                case OP_MUL: op_type = IR_MUL; break;
                case OP_DIV: op_type = IR_DIV; break;
                case OP_MOD: op_type = IR_MOD; break;
                case OP_EQ:  op_type = IR_EQ;  break;
                case OP_NE:  op_type = IR_NE;  break;
                case OP_LT:  op_type = IR_LT;  break;
                case OP_GT:  op_type = IR_GT;  break;
                case OP_LE:  op_type = IR_LE;  break;
                case OP_GE:  op_type = IR_GE;  break;
                default:     op_type = IR_ADD; break; // Default case
            }
            
            IRNode *op_node = create_ir_node(op_type, temp, left_code->dest, right_code->dest);
            
            // Find the end of the combined code
            last = code;
            while (last->next) last = last->next;
            last->next = op_node;
            
            return code;
        }
        
        case NODE_ASSIGN: {
            // Generate code for the right-hand side
            IRNode *rhs_code = generate_ir(ast->data.assign.value);
            if (!rhs_code) return NULL;
            
            // Create the assignment node
            IRNode *assign_node = create_ir_node(IR_ASSIGN, ast->data.assign.var_name, 
                                               rhs_code->dest, NULL);
            if (!assign_node) return NULL;
            
            // Append assignment to the end of rhs_code
            IRNode *last = rhs_code;
            while (last->next) last = last->next;
            last->next = assign_node;
            
            return rhs_code;
        }
        
        case NODE_IF: {
            // Generate code for condition
            IRNode *cond_code = generate_ir(ast->data.if_stmt.condition);
            if (!cond_code) return NULL;
            
            // Create labels
            char *false_label = create_label();
            if (!false_label) return NULL;
            
            char *end_label = create_label();
            if (!end_label) {
                free(false_label);
                return NULL;
            }
            
            // Create conditional jump
            IRNode *jump_node = create_ir_node(IR_JUMPZ, false_label, cond_code->dest, NULL);
            if (!jump_node) {
                free(false_label);
                free(end_label);
                return NULL;
            }
            
            // Generate code for then block
            IRNode *then_code = generate_ir(ast->data.if_stmt.then_block);
            if (!then_code) {
                free(false_label);
                free(end_label);
                return NULL;
            }
            
            // Generate code for else block if it exists
            IRNode *else_code = NULL;
            if (ast->data.if_stmt.else_block) {
                else_code = generate_ir(ast->data.if_stmt.else_block);
                if (!else_code) {
                    free(false_label);
                    free(end_label);
                    return NULL;
                }
            }
            
            // Create jump to end (after then block)
            IRNode *end_jump = create_ir_node(IR_JUMP, end_label, NULL, NULL);
            if (!end_jump) {
                free(false_label);
                free(end_label);
                return NULL;
            }
            
            // Create labels
            IRNode *false_label_node = create_ir_node(IR_LABEL, false_label, NULL, NULL);
            IRNode *end_label_node = create_ir_node(IR_LABEL, end_label, NULL, NULL);
            if (!false_label_node || !end_label_node) {
                free(false_label);
                free(end_label);
                return NULL;
            }
            
            // Combine all the code
            code = cond_code;
            
            IRNode *last = code;
            while (last->next) last = last->next;
            last->next = jump_node;
            
            last = last->next;
            last->next = then_code;
            
            while (last->next) last = last->next;
            last->next = end_jump;
            
            last = last->next;
            last->next = false_label_node;
            
            if (else_code) {
                last = last->next;
                last->next = else_code;
                
                while (last->next) last = last->next;
            }
            
            last->next = end_label_node;
            
            return code;
        }

        case NODE_ID: {
            temp = create_temp_var();
            if (!temp) {
                fprintf(stderr, "Memory allocation failed\n");
                return NULL;
            }
            code = create_ir_node(IR_LOAD, temp, ast->data.id_name, NULL);
            return code;
        }

        case NODE_WHILE: {
            // Create labels
            char *start_label = create_label();
            if (!start_label) return NULL;
            
            char *end_label = create_label();
            if (!end_label) {
                free(start_label);
                return NULL;
            }
            
            // Create start label
            IRNode *start_label_node = create_ir_node(IR_LABEL, start_label, NULL, NULL);
            if (!start_label_node) {
                free(start_label);
                free(end_label);
                return NULL;
            }
            
            // Generate condition code
            IRNode *cond_code = generate_ir(ast->data.loop.condition);
            if (!cond_code) {
                free(start_label);
                free(end_label);
                return NULL;
            }
            
            // Create conditional jump
            IRNode *jump_node = create_ir_node(IR_JUMPZ, end_label, cond_code->dest, NULL);
            if (!jump_node) {
                free(start_label);
                free(end_label);
                return NULL;
            }
            
            // Generate body code
            IRNode *body_code = generate_ir(ast->data.loop.body);
            if (!body_code) {
                free(start_label);
                free(end_label);
                return NULL;
            }
            
            // Create jump back to start
            IRNode *back_jump = create_ir_node(IR_JUMP, start_label, NULL, NULL);
            if (!back_jump) {
                free(start_label);
                free(end_label);
                return NULL;
            }
            
            // Create end label
            IRNode *end_label_node = create_ir_node(IR_LABEL, end_label, NULL, NULL);
            if (!end_label_node) {
                free(start_label);
                free(end_label);
                return NULL;
            }
            
            // Combine all the code
            code = start_label_node;
            code->next = cond_code;
            
            IRNode *last = cond_code;
            while (last->next) last = last->next;
            last->next = jump_node;
            
            last = last->next;
            last->next = body_code;
            
            while (last->next) last = last->next;
            last->next = back_jump;
            
            last = last->next;
            last->next = end_label_node;
            
            return code;
        }

        case NODE_FOR: {
            // Handle initialization
            IRNode *init_code = NULL;
            if (ast->data.loop.init) {
                init_code = generate_ir(ast->data.loop.init);
                if (!init_code && ast->data.loop.init) return NULL;
            }
            
            // Create labels
            char *start_label = create_label();
            if (!start_label) return NULL;
            
            char *end_label = create_label();
            if (!end_label) {
                free(start_label);
                return NULL;
            }
            
            // Create start label
            IRNode *start_label_node = create_ir_node(IR_LABEL, start_label, NULL, NULL);
            if (!start_label_node) {
                free(start_label);
                free(end_label);
                return NULL;
            }
            
            // Generate condition code
            IRNode *cond_code = NULL;
            if (ast->data.loop.condition) {
                cond_code = generate_ir(ast->data.loop.condition);
                if (!cond_code) {
                    free(start_label);
                    free(end_label);
                    return NULL;
                }
            } else {
                // If no condition, create a constant true condition
                temp = create_temp_var();
                if (!temp) {
                    free(start_label);
                    free(end_label);
                    return NULL;
                }
                
                cond_code = create_ir_node(IR_ASSIGN, temp, "1", NULL);
                if (!cond_code) {
                    free(start_label);
                    free(end_label);
                    free(temp);
                    return NULL;
                }
            }
            
            // Create conditional jump
            IRNode *jump_node = create_ir_node(IR_JUMPZ, end_label, cond_code->dest, NULL);
            if (!jump_node) {
                free(start_label);
                free(end_label);
                return NULL;
            }
            
            // Generate body code
            IRNode *body_code = NULL;
            if (ast->data.loop.body) {
                body_code = generate_ir(ast->data.loop.body);
                if (!body_code) {
                    free(start_label);
                    free(end_label);
                    return NULL;
                }
            }
            
            // Generate update code
            IRNode *update_code = NULL;
            if (ast->data.loop.update) {
                update_code = generate_ir(ast->data.loop.update);
                if (!update_code && ast->data.loop.update) {
                    free(start_label);
                    free(end_label);
                    return NULL;
                }
            }
            
            // Create jump back to start
            IRNode *back_jump = create_ir_node(IR_JUMP, start_label, NULL, NULL);
            if (!back_jump) {
                free(start_label);
                free(end_label);
                return NULL;
            }
            
            // Create end label
            IRNode *end_label_node = create_ir_node(IR_LABEL, end_label, NULL, NULL);
            if (!end_label_node) {
                free(start_label);
                free(end_label);
                return NULL;
            }
            
            // Combine all the code
            if (init_code) {
                code = init_code;
                IRNode *last = code;
                while (last->next) last = last->next;
                last->next = start_label_node;
            } else {
                code = start_label_node;
            }
            
            IRNode *last = code;
            while (last->next) last = last->next;
            last->next = cond_code;
            
            while (last->next) last = last->next;
            last->next = jump_node;
            
            if (body_code) {
                last = last->next;
                last->next = body_code;
                
                while (last->next) last = last->next;
            }
            
            if (update_code) {
                last->next = update_code;
                
                while (last->next) last = last->next;
            }
            
            last->next = back_jump;
            last = last->next;
            last->next = end_label_node;
            
            return code;
        }

        case NODE_FLOAT: {
            temp = create_temp_var();
            if (!temp) {
                fprintf(stderr, "Memory allocation failed\n");
                return NULL;
            }
            
            // Convert float to string
            char value[30]; // Enough for float precision
            sprintf(value, "%f", ast->data.float_val);
            
            code = create_ir_node(IR_ASSIGN, temp, value, NULL);
            return code;
        }

        case NODE_STRING: {
            temp = create_temp_var();
            if (!temp) {
                fprintf(stderr, "Memory allocation failed\n");
                return NULL;
            }
            
            // Use the string value directly
            code = create_ir_node(IR_ASSIGN, temp, ast->data.str_val, NULL);
            return code;
        }
        
        // Add other cases for different AST node types
        
        default:
            printf("Unsupported AST node type for IR generation\n");
            return create_ir_node(IR_ASSIGN, "error", "unsupported", NULL);
    }
}

// Free an IR list
void free_ir_list(IRNode *head) {
    while (head) {
        IRNode *temp = head;
        head = head->next;
        
        if (temp->dest) free(temp->dest);
        if (temp->src1) free(temp->src1);
        if (temp->src2) free(temp->src2);
        free(temp);
    }
}

// Print the IR in a readable format
void print_ir(IRNode *head) {
    while (head) {
        switch (head->op) {
            case IR_ADD:
                printf("%s = %s + %s\n", head->dest, head->src1, head->src2);
                break;
            case IR_SUB:
                printf("%s = %s - %s\n", head->dest, head->src1, head->src2);
                break;
            case IR_MUL:
                printf("%s = %s * %s\n", head->dest, head->src1, head->src2);
                break;
            case IR_DIV:
                printf("%s = %s / %s\n", head->dest, head->src1, head->src2);
                break;
            case IR_MOD:
                printf("%s = %s %% %s\n", head->dest, head->src1, head->src2);
                break;
            case IR_ASSIGN:
                printf("%s = %s\n", head->dest, head->src1);
                break;
            case IR_LABEL:
                printf("%s:\n", head->dest);
                break;
            case IR_JUMP:
                printf("goto %s\n", head->dest);
                break;
            case IR_JUMPZ:
                printf("if %s == 0 goto %s\n", head->src1, head->dest);
                break;
            case IR_JUMPNZ:
                printf("if %s != 0 goto %s\n", head->src1, head->dest);
                break;
            // Add more cases for other IR operations
            default:
                printf("Unknown IR operation\n");
        }
        head = head->next;
    }
}