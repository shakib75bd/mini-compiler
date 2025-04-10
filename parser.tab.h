/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_VAL = 258,
     FLOAT_VAL = 259,
     CHAR_VAL = 260,
     STRING_VAL = 261,
     ID = 262,
     INT = 263,
     FLOAT = 264,
     CHAR_TYPE = 265,
     VOID = 266,
     RETURN = 267,
     IF = 268,
     ELSE = 269,
     WHILE = 270,
     FOR = 271,
     AND = 272,
     OR = 273,
     NOT = 274,
     LE = 275,
     GE = 276,
     LT = 277,
     GT = 278,
     EQ = 279,
     NE = 280,
     INC = 281,
     DEC = 282,
     PLUS_ASSIGN = 283,
     MINUS_ASSIGN = 284,
     MULT_ASSIGN = 285,
     DIV_ASSIGN = 286,
     END = 287,
     UMINUS = 288,
     LOWER_THAN_ELSE = 289
   };
#endif
/* Tokens.  */
#define INT_VAL 258
#define FLOAT_VAL 259
#define CHAR_VAL 260
#define STRING_VAL 261
#define ID 262
#define INT 263
#define FLOAT 264
#define CHAR_TYPE 265
#define VOID 266
#define RETURN 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define FOR 271
#define AND 272
#define OR 273
#define NOT 274
#define LE 275
#define GE 276
#define LT 277
#define GT 278
#define EQ 279
#define NE 280
#define INC 281
#define DEC 282
#define PLUS_ASSIGN 283
#define MINUS_ASSIGN 284
#define MULT_ASSIGN 285
#define DIV_ASSIGN 286
#define END 287
#define UMINUS 288
#define LOWER_THAN_ELSE 289




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 18 "parser.y"
{
    int intval;
    float floatval;
    char charval;
    char *strval;
    ASTNode *ast;  // Add AST type
}
/* Line 1529 of yacc.c.  */
#line 125 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

