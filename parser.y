%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"  // Include the AST header
#include "ir.h"   // Add this to the includes section

/* Declarations for Flex */
extern FILE *yyin;
extern int yylex(void);
extern int yyparse(void);
extern int yylineno;
void yyerror(const char *s);

/* For AST evaluation */
ASTNode *root = NULL;
%}

%union {
    int intval;
    float floatval;
    char charval;
    char *strval;
    ASTNode *ast;  // Add AST type
}

/* Tokens */
%token <intval> INT_VAL
%token <floatval> FLOAT_VAL
%token <charval> CHAR_VAL
%token <strval> STRING_VAL ID

%token INT FLOAT CHAR_TYPE VOID RETURN
%token IF ELSE WHILE FOR
%token AND OR NOT LE GE LT GT EQ NE INC DEC
%token PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN
%token END

/* Non-terminals with types */
%type <ast> expression expression_opt
%type <ast> statement statements
%type <ast> if_statement while_statement for_statement
%type <ast> compound_statement return_statement
%type <ast> declaration assignment for_init
%type <ast> argument_list  /* Add this line */

/* Operator precedence */
%nonassoc '['
%left OR
%left AND
%left EQ NE
%left LE GE LT GT
%left '+' '-'
%left '*' '/' '%'
%right NOT UMINUS
%right INC DEC

/* Resolve dangling else */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

program: 
    statements END { 
        printf("\nProgram is syntactically correct!\n"); 
        if ($1 != NULL) {
            int result = evaluate_ast($1);
            printf("Program evaluation result: %d\n", result);
            
            // Debug
            printf("Generating IR code...\n");
            IRNode *ir_code = generate_ir($1);
            printf("IR code %s generated\n", ir_code ? "successfully" : "failed to be");
            
            if (ir_code) {
                printf("\n--- Intermediate Code ---\n");
                print_ir(ir_code);
                free_ir_list(ir_code);
            } else {
                printf("No intermediate code was generated\n");
            }
            
            free_ast($1);
        }
        exit(0); 
    }
    | expression END {
        printf("\nExpression is syntactically correct!\n");
        int result = evaluate_ast($1);
        printf("Expression evaluation result: %d\n", result);
        
        // Debug
        printf("Generating IR code...\n");
        IRNode *ir_code = generate_ir($1);
        printf("IR code %s generated\n", ir_code ? "successfully" : "failed to be");
        
        if (ir_code) {
            printf("\n--- Intermediate Code ---\n");
            print_ir(ir_code);
            free_ir_list(ir_code);
        } else {
            printf("No intermediate code was generated\n");
        }
        
        free_ast($1);
        exit(0);
    }
    ;

statements: 
    statement { $$ = $1; }
    | statements statement { 
        // In a real compiler, you'd create a block node here
        // For simplicity, we'll just evaluate the last statement
        free_ast($1);
        $$ = $2; 
    }
    ;

statement:
    declaration ';' { $$ = $1; }
    | expression ';' { $$ = $1; }
    | assignment ';' { $$ = $1; }
    | if_statement { $$ = $1; }
    | while_statement { $$ = $1; }
    | for_statement { $$ = $1; }
    | compound_statement { $$ = $1; }
    | return_statement ';' { $$ = $1; }
    ;

declaration:
    type ID { 
        printf("DECLARE: %s\n", $2);
        $$ = NULL; // For simplicity
    }
    | type ID '=' expression { 
        printf("DECLARE_ASSIGN: %s\n", $2);
        $$ = create_assign_node($2, $4);
    }
    | type ID '[' INT_VAL ']' { 
        printf("DECLARE ARRAY: %s[%d]\n", $2, $4);
        $$ = NULL; // For simplicity
    }
    ;

type:
    INT
    | FLOAT
    | CHAR_TYPE
    | VOID
    ;

assignment:
    ID '=' expression { 
        printf("ASSIGN: %s\n", $1);
        $$ = create_assign_node($1, $3);
    }
    | ID PLUS_ASSIGN expression { 
        printf("PLUS_ASSIGN: %s\n", $1);
        // Create AST for ID + expression, then assign
        ASTNode *id_node = create_id_node($1);
        ASTNode *add_node = create_binop_node(OP_ADD, id_node, $3);
        $$ = create_assign_node($1, add_node);
    }
    /* Handle other assignments similarly */
    ;

expression:
    ID { 
        printf("VAR: %s\n", $1);
        $$ = create_id_node($1);
    }
    | INT_VAL { 
        printf("INT: %d\n", $1);
        $$ = create_int_node($1);
    }
    | STRING_VAL { 
        printf("STRING: %s\n", $1);
        $$ = create_string_node($1);
    }
    | FLOAT_VAL { 
        printf("FLOAT: %f\n", $1);
        $$ = create_float_node($1);
    }
    | expression '+' expression { 
        printf("ADD\n");
        $$ = create_binop_node(OP_ADD, $1, $3);
    }
    | expression '-' expression { 
        printf("SUBTRACT\n");
        $$ = create_binop_node(OP_SUB, $1, $3); 
    }
    | expression '*' expression { 
        printf("MULTIPLY\n");
        $$ = create_binop_node(OP_MUL, $1, $3);
    }
    | expression '/' expression { 
        printf("DIVIDE\n");
        $$ = create_binop_node(OP_DIV, $1, $3);
    }
    | expression '%' expression { 
        printf("MODULO\n");
        $$ = create_binop_node(OP_MOD, $1, $3);
    }
    | expression EQ expression { 
        printf("EQUALS\n");
        $$ = create_binop_node(OP_EQ, $1, $3);
    }
    | expression NE expression { 
        printf("NOT_EQUALS\n");
        $$ = create_binop_node(OP_NE, $1, $3);
    }
    | expression LT expression { 
        printf("LESS_THAN\n");
        $$ = create_binop_node(OP_LT, $1, $3);
    }
    | expression GT expression { 
        printf("GREATER_THAN\n");
        $$ = create_binop_node(OP_GT, $1, $3);
    }
    | expression LE expression { 
        printf("LESS_EQUAL\n");
        $$ = create_binop_node(OP_LE, $1, $3);
    }
    | expression GE expression { 
        printf("GREATER_EQUAL\n");
        $$ = create_binop_node(OP_GE, $1, $3);
    }
    | expression AND expression { 
        printf("LOGICAL_AND\n");
        $$ = create_binop_node(OP_AND, $1, $3);
    }
    | expression OR expression { 
        printf("LOGICAL_OR\n");
        $$ = create_binop_node(OP_OR, $1, $3);
    }
    | NOT expression { 
        printf("LOGICAL_NOT\n");
        $$ = create_unaryop_node(OP_NOT, $2);
    }
    | '-' expression %prec UMINUS { 
        printf("NEGATE\n");
        $$ = create_unaryop_node(OP_NEG, $2);
    }
    | ID INC { 
        printf("POST_INCREMENT: %s\n", $1);
        $$ = create_unaryop_node(OP_INC, create_id_node($1));
    }
    | ID DEC { 
        printf("POST_DECREMENT: %s\n", $1);
        $$ = create_unaryop_node(OP_DEC, create_id_node($1));
    }
    | ID '(' ')' { 
        printf("FUNCTION_CALL: %s()\n", $1);
        $$ = create_funcall_node($1, NULL, 0);
    }
    | ID '(' argument_list ')' { 
        printf("FUNCTION_CALL_WITH_ARGS: %s(...)\n", $1);
        // $3 is now an argument list node, use its fields
        $$ = create_funcall_node($1, $3->data.funcall.args, $3->data.funcall.arg_count);
        free($3);  // Free the argument list node but not its args
    }
    | '(' expression ')' { $$ = $2; }
    ;

if_statement:
    IF '(' expression ')' statement %prec LOWER_THAN_ELSE { 
        printf("IF\n");
        $$ = NULL; // To be implemented
    }
    | IF '(' expression ')' statement ELSE statement { 
        printf("IF-ELSE\n");
        $$ = NULL; // To be implemented
    }
    ;

while_statement:
    WHILE '(' expression ')' statement { 
        printf("WHILE\n");
        $$ = NULL; // To be implemented
    }
    ;

for_statement:
    FOR '(' for_init ';' expression_opt ';' expression_opt ')' statement { 
        printf("FOR\n");
        $$ = NULL; // To be implemented
    }
    ;

for_init:
    /* empty */ { $$ = NULL; }
    | expression { $$ = $1; }
    | assignment { $$ = $1; }
    | declaration { $$ = $1; }
    ;

compound_statement:
    '{' statements '}' { $$ = $2; }
    | '{' '}' { $$ = NULL; }
    ;

return_statement:
    RETURN { 
        printf("RETURN\n");
        $$ = NULL; 
    }
    | RETURN expression { 
        printf("RETURN VALUE\n");
        $$ = NULL; // To be implemented
    }
    ;

expression_opt:
    /* empty */ { $$ = NULL; }
    | expression { $$ = $1; }
    ;

argument_list:
    expression { 
        printf("ARGUMENT\n");
        // Create an array with a single argument
        ASTNode **args = malloc(sizeof(ASTNode*));
        args[0] = $1;
        $$ = create_argument_list_node(args, 1);
    }
    | argument_list ',' expression { 
        printf("ARGUMENT_LIST\n");
        // Add the new expression to the existing argument list
        int new_count = $1->data.funcall.arg_count + 1;
        ASTNode **new_args = malloc(new_count * sizeof(ASTNode*));
        
        // Copy existing arguments
        for(int i = 0; i < $1->data.funcall.arg_count; i++) {
            new_args[i] = $1->data.funcall.args[i];
        }
        
        // Add the new argument
        new_args[new_count - 1] = $3;
        
        // Create a new argument list node
        $$ = create_argument_list_node(new_args, new_count);
    }
    ;

%%

// Error handling function
void yyerror(const char *s) {  
    fprintf(stderr, "Syntax Error: %s at line %d\n", s, yylineno);  
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    yyin = file;  // Set the input stream for Flex
    yyparse();

    fclose(file);
    return 0;
}
