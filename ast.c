#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

// Create an integer node
ASTNode* create_int_node(int value) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    node->type = NODE_INT;
    node->data.int_val = value;
    return node;
}

// Create a float node
ASTNode* create_float_node(float value) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    node->type = NODE_FLOAT;
    node->data.float_val = value;
    return node;
}

// Create an identifier node
ASTNode* create_id_node(char *name) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    node->type = NODE_ID;
    node->data.id_name = strdup(name);
    return node;
}

// Create a binary operation node
ASTNode* create_binop_node(BinOpType op, ASTNode *left, ASTNode *right) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    node->type = NODE_BINOP;
    node->data.bin_op.op = op;
    node->data.bin_op.left = left;
    node->data.bin_op.right = right;
    return node;
}

// Create a unary operation node
ASTNode* create_unaryop_node(UnaryOpType op, ASTNode *expr) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    node->type = NODE_UNARYOP;
    node->data.unary_op.op = op;
    node->data.unary_op.expr = expr;
    return node;
}

// Create an assignment node
ASTNode* create_assign_node(char *var_name, ASTNode *value) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    node->type = NODE_ASSIGN;
    node->data.assign.var_name = strdup(var_name);
    node->data.assign.value = value;
    return node;
}

// Create a function call node
ASTNode* create_funcall_node(char *name, ASTNode **args, int arg_count) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    node->type = NODE_FUNCALL;
    node->data.funcall.func_name = name ? strdup(name) : NULL;
    node->data.funcall.args = args;
    node->data.funcall.arg_count = arg_count;
    return node;
}

// Create an argument list node (used when building function calls)
ASTNode* create_argument_list_node(ASTNode **args, int arg_count) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    node->type = NODE_FUNCALL;  // Reuse function call type for argument lists
    node->data.funcall.func_name = NULL;  // No function name for arg lists
    node->data.funcall.args = args;
    node->data.funcall.arg_count = arg_count;
    return node;
}

// Create a string node
ASTNode* create_string_node(char *value) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    node->type = NODE_STRING;
    
    // Handle NULL string
    if (!value) {
        node->data.str_val = strdup("");
        return node;
    }
    
    // Remove the quotes from the string literal
    int len = strlen(value);
    if (len >= 2 && value[0] == '"' && value[len-1] == '"') {
        // Copy without the quotes
        node->data.str_val = strndup(value + 1, len - 2);
    } else {
        node->data.str_val = strdup(value);
    }
    
    return node;
}

// Free an AST node and all its children
void free_ast(ASTNode *node) {
    if (node == NULL) return;
    
    switch (node->type) {
        case NODE_ID:
            free(node->data.id_name);
            break;
        case NODE_STRING:  // Add this case to handle string nodes
            free(node->data.str_val);
            break;
        case NODE_BINOP:
            free_ast(node->data.bin_op.left);
            free_ast(node->data.bin_op.right);
            break;
        case NODE_UNARYOP:
            free_ast(node->data.unary_op.expr);
            break;
        case NODE_ASSIGN:
            free(node->data.assign.var_name);
            free_ast(node->data.assign.value);
            break;
        case NODE_IF:
            free_ast(node->data.if_stmt.condition);
            free_ast(node->data.if_stmt.then_block);
            if (node->data.if_stmt.else_block)
                free_ast(node->data.if_stmt.else_block);
            break;
        case NODE_WHILE:
        case NODE_FOR:
            free_ast(node->data.loop.condition);
            free_ast(node->data.loop.body);
            if (node->data.loop.init)
                free_ast(node->data.loop.init);
            if (node->data.loop.update)
                free_ast(node->data.loop.update);
            break;
        case NODE_BLOCK:
            for (int i = 0; i < node->data.block.count; i++) {
                free_ast(node->data.block.statements[i]);
            }
            free(node->data.block.statements);
            break;
        case NODE_FUNCALL:
            if (node->data.funcall.func_name)
                free(node->data.funcall.func_name);
            if (node->data.funcall.args) {
                for (int i = 0; i < node->data.funcall.arg_count; i++) {
                    free_ast(node->data.funcall.args[i]);
                }
                free(node->data.funcall.args);
            }
            break;
        default:
            break;
    }
    free(node);
}

// Simple symbol table (for demonstration)
#define MAX_VARS 100
struct {
    char *name;
    int value;
} symbol_table[MAX_VARS];
int var_count = 0;

// Get variable value or return 0 if not found
int get_var_value(char *name) {
    if (!name) return 0;
    
    for (int i = 0; i < var_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return symbol_table[i].value;
        }
    }
    // Variable not found, create it
    if (var_count < MAX_VARS) {
        symbol_table[var_count].name = strdup(name);
        symbol_table[var_count].value = 0;
        var_count++;
        return 0;
    }
    fprintf(stderr, "Symbol table full\n");
    return 0;
}

// Set variable value
void set_var_value(char *name, int value) {
    if (!name) return;
    
    for (int i = 0; i < var_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            symbol_table[i].value = value;
            return;
        }
    }
    // Variable not found, create it
    if (var_count < MAX_VARS) {
        symbol_table[var_count].name = strdup(name);
        symbol_table[var_count].value = value;
        var_count++;
        return;
    }
    fprintf(stderr, "Symbol table full\n");
}

// Simple printf format processing
void handle_printf(ASTNode *node) {
    if (!node || !node->data.funcall.arg_count) return;
    
    if (node->data.funcall.args[0]->type == NODE_STRING) {
        // Get the format string
        const char *format = node->data.funcall.args[0]->data.str_val;
        if (!format) return;
        
        // Count format specifiers
        int format_count = 0;
        for (const char *p = format; *p; p++) {
            if (*p == '%' && *(p+1) != '%') {
                format_count++;
            }
        }
        
        // Simple implementation: just print the format string and values
        if (format_count == 0 || node->data.funcall.arg_count == 1) {
            printf("%s", format);
        } else {
            // Very basic handling of format specifiers
            int arg_idx = 1;
            for (const char *p = format; *p; p++) {
                if (*p == '%' && *(p+1) != '%') {
                    if (arg_idx < node->data.funcall.arg_count) {
                        printf("%d", evaluate_ast(node->data.funcall.args[arg_idx++]));
                    }
                } else {
                    putchar(*p);
                }
            }
        }
    } else {
        // If first argument is not a string, just print its value
        printf("%d", evaluate_ast(node->data.funcall.args[0]));
    }
}

// Evaluate AST expressions
int evaluate_ast(ASTNode *node) {
    if (node == NULL) return 0;
    
    switch (node->type) {
        case NODE_INT:
            return node->data.int_val;
        case NODE_FLOAT:
            return (int)node->data.float_val; // Truncate to int for simplicity
        case NODE_STRING:
            // Strings evaluate to 0 in numeric context
            return 0;
        case NODE_ID:
            return get_var_value(node->data.id_name);
        case NODE_BINOP:
            switch (node->data.bin_op.op) {
                case OP_ADD:
                    return evaluate_ast(node->data.bin_op.left) + evaluate_ast(node->data.bin_op.right);
                case OP_SUB:
                    return evaluate_ast(node->data.bin_op.left) - evaluate_ast(node->data.bin_op.right);
                case OP_MUL:
                    return evaluate_ast(node->data.bin_op.left) * evaluate_ast(node->data.bin_op.right);
                case OP_DIV: {
                    int divisor = evaluate_ast(node->data.bin_op.right);
                    if (divisor == 0) {
                        fprintf(stderr, "Error: Division by zero\n");
                        return 0;
                    }
                    return evaluate_ast(node->data.bin_op.left) / divisor;
                }
                case OP_MOD: {
                    int divisor = evaluate_ast(node->data.bin_op.right);
                    if (divisor == 0) {
                        fprintf(stderr, "Error: Modulo by zero\n");
                        return 0;
                    }
                    return evaluate_ast(node->data.bin_op.left) % divisor;
                }
                case OP_EQ:
                    return evaluate_ast(node->data.bin_op.left) == evaluate_ast(node->data.bin_op.right);
                case OP_NE:
                    return evaluate_ast(node->data.bin_op.left) != evaluate_ast(node->data.bin_op.right);
                case OP_LT:
                    return evaluate_ast(node->data.bin_op.left) < evaluate_ast(node->data.bin_op.right);
                case OP_GT:
                    return evaluate_ast(node->data.bin_op.left) > evaluate_ast(node->data.bin_op.right);
                case OP_LE:
                    return evaluate_ast(node->data.bin_op.left) <= evaluate_ast(node->data.bin_op.right);
                case OP_GE:
                    return evaluate_ast(node->data.bin_op.left) >= evaluate_ast(node->data.bin_op.right);
                case OP_AND:
                    return evaluate_ast(node->data.bin_op.left) && evaluate_ast(node->data.bin_op.right);
                case OP_OR:
                    return evaluate_ast(node->data.bin_op.left) || evaluate_ast(node->data.bin_op.right);
                case OP_ASSIGN:
                    // This shouldn't happen in a binary op, but handle anyway
                    return 0;
                default:
                    fprintf(stderr, "Unknown binary operator\n");
                    return 0;
            }
        case NODE_UNARYOP:
            switch (node->data.unary_op.op) {
                case OP_NEG:
                    return -evaluate_ast(node->data.unary_op.expr);
                case OP_NOT:
                    return !evaluate_ast(node->data.unary_op.expr);
                case OP_INC: {
                    if (node->data.unary_op.expr->type == NODE_ID) {
                        char *name = node->data.unary_op.expr->data.id_name;
                        int val = get_var_value(name);
                        set_var_value(name, val + 1);
                        return val + 1;
                    }
                    return 0;
                }
                case OP_DEC: {
                    if (node->data.unary_op.expr->type == NODE_ID) {
                        char *name = node->data.unary_op.expr->data.id_name;
                        int val = get_var_value(name);
                        set_var_value(name, val - 1);
                        return val - 1;
                    }
                    return 0;
                }
                default:
                    fprintf(stderr, "Unknown unary operator\n");
                    return 0;
            }
        case NODE_ASSIGN:
            set_var_value(node->data.assign.var_name, 
                         evaluate_ast(node->data.assign.value));
            return get_var_value(node->data.assign.var_name);
        case NODE_FUNCALL:
            // Special handling for printf
            if (node->data.funcall.func_name && 
                strcmp(node->data.funcall.func_name, "printf") == 0) {
                handle_printf(node);
                return 0;
            }
            
            // For other function calls, just return 0
            // In a real interpreter, you'd look up the function and call it
            return 0;
        case NODE_IF:
            if (evaluate_ast(node->data.if_stmt.condition)) {
                return evaluate_ast(node->data.if_stmt.then_block);
            } else if (node->data.if_stmt.else_block) {
                return evaluate_ast(node->data.if_stmt.else_block);
            }
            return 0;
        case NODE_WHILE: {
            int last_result = 0;
            while (evaluate_ast(node->data.loop.condition)) {
                last_result = evaluate_ast(node->data.loop.body);
            }
            return last_result;
        }
        case NODE_FOR: {
            int last_result = 0;
            if (node->data.loop.init) {
                evaluate_ast(node->data.loop.init);
            }
            while (evaluate_ast(node->data.loop.condition)) {
                last_result = evaluate_ast(node->data.loop.body);
                if (node->data.loop.update) {
                    evaluate_ast(node->data.loop.update);
                }
            }
            return last_result;
        }
        case NODE_BLOCK: {
            int last_result = 0;
            for (int i = 0; i < node->data.block.count; i++) {
                last_result = evaluate_ast(node->data.block.statements[i]);
            }
            return last_result;
        }
        default:
            fprintf(stderr, "Cannot evaluate this node type: %d\n", node->type);
            return 0;
    }
}