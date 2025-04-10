#ifndef IR_H
#define IR_H

// Forward declaration of ASTNode from ast.h
struct ASTNode;

typedef enum {
    IR_ADD, IR_SUB, IR_MUL, IR_DIV, IR_MOD,
    IR_ASSIGN, IR_LOAD, IR_STORE,
    IR_LABEL, IR_JUMP, IR_JUMPZ, IR_JUMPNZ,
    IR_LT, IR_GT, IR_LE, IR_GE, IR_EQ, IR_NE,
    IR_CALL, IR_RETURN,
    IR_PARAM, IR_ARG
} IROpType;

typedef struct IRNode {
    IROpType op;
    char *dest;        // Destination operand
    char *src1;        // Source operand 1
    char *src2;        // Source operand 2
    int labelNum;      // For jumps and labels
    struct IRNode *next;
} IRNode;

// Function prototypes
IRNode* create_ir_node(IROpType op, char *dest, char *src1, char *src2);
void free_ir_list(IRNode *head);
void print_ir(IRNode *head);
char* create_temp_var();
char* create_label();
IRNode* append_ir_node(IRNode *head, IRNode *node);

// Now this works with the forward declaration
IRNode* generate_ir(struct ASTNode *ast);

#endif /* IR_H */