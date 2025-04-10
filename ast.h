#ifndef AST_H
#define AST_H

typedef enum {
    NODE_INT,         // Integer literal
    NODE_FLOAT,       // Float literal
    NODE_ID,          // Variable/identifier
    NODE_BINOP,       // Binary operation
    NODE_UNARYOP,     // Unary operation
    NODE_ASSIGN,      // Assignment
    NODE_IF,          // If statement
    NODE_WHILE,       // While loop
    NODE_FOR,         // For loop
    NODE_BLOCK,       // Compound statement
    NODE_FUNCALL,     // Function call
    NODE_RETURN,
    NODE_STRING       // Return statement
} NodeType;

// Binary operators
typedef enum {
    OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD,
    OP_EQ, OP_NE, OP_LT, OP_GT, OP_LE, OP_GE,
    OP_AND, OP_OR, OP_ASSIGN
} BinOpType;

// Unary operators
typedef enum {
    OP_NEG, OP_NOT, OP_INC, OP_DEC
} UnaryOpType;

// AST node structure
typedef struct ASTNode {
    NodeType type;
    union {
        int int_val;                  // For NODE_INT
        float float_val;              // For NODE_FLOAT
        char *id_name;
        char *str_val;                // For NODE_ID
        
        struct {                      // For NODE_BINOP
            BinOpType op;
            struct ASTNode *left;
            struct ASTNode *right;
        } bin_op;
        
        struct {                      // For NODE_UNARYOP
            UnaryOpType op;
            struct ASTNode *expr;
        } unary_op;
        
        struct {                      // For NODE_ASSIGN
            char *var_name;
            struct ASTNode *value;
        } assign;
        
        struct {                      // For NODE_IF
            struct ASTNode *condition;
            struct ASTNode *then_block;
            struct ASTNode *else_block;
        } if_stmt;
        
        struct {                      // For NODE_WHILE/FOR
            struct ASTNode *condition;
            struct ASTNode *body;
            struct ASTNode *init;     // Only for FOR
            struct ASTNode *update;   // Only for FOR
        } loop;
        
        struct {                      // For NODE_BLOCK
            struct ASTNode **statements;
            int count;
        } block;
        
        struct {                      // For NODE_FUNCALL
            char *func_name;
            struct ASTNode **args;
            int arg_count;
        } funcall;
    } data;
} ASTNode;

// Function prototypes
ASTNode* create_int_node(int value);
ASTNode* create_float_node(float value);
ASTNode* create_id_node(char *name);
ASTNode* create_binop_node(BinOpType op, ASTNode *left, ASTNode *right);
ASTNode* create_unaryop_node(UnaryOpType op, ASTNode *expr);
ASTNode* create_assign_node(char *var_name, ASTNode *value);
// Add this with your other function declarations
ASTNode* create_string_node(char *value);

// Add these missing function declarations
ASTNode* create_funcall_node(char *name, ASTNode **args, int arg_count);
ASTNode* create_argument_list_node(ASTNode **args, int arg_count);

void free_ast(ASTNode *node);

// Evaluation function prototype
int evaluate_ast(ASTNode *node);

#endif /* AST_H */