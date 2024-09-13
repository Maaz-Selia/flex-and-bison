/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_SPL_TAB_H_INCLUDED
# define YY_YY_SPL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FULLSTOP = 258,
    COMMA = 259,
    COLON = 260,
    SEMICOLON = 261,
    ASSIGN = 262,
    BRA = 263,
    KET = 264,
    EQUAL = 265,
    NOT_EQUAL = 266,
    LESS_THAN = 267,
    GREATER_THAN = 268,
    LESS_THAN_OR_EQUAL = 269,
    GREATER_THAN_OR_EQUAL = 270,
    PLUS = 271,
    MINUS = 272,
    TIMES = 273,
    DIVIDE = 274,
    APOSTROPHE = 275,
    ENDP = 276,
    DECLARATIONS = 277,
    CODE = 278,
    OF = 279,
    TYPE = 280,
    CHARACTER = 281,
    INTEGER = 282,
    REAL = 283,
    IF = 284,
    THEN = 285,
    ENDIF = 286,
    ELSE = 287,
    DO = 288,
    WHILE = 289,
    ENDDO = 290,
    ENDWHILE = 291,
    FOR = 292,
    IS = 293,
    BY = 294,
    TO = 295,
    ENDFOR = 296,
    WRITE = 297,
    READ = 298,
    NEWLINE = 299,
    NOT = 300,
    AND = 301,
    OR = 302,
    LETTER = 303,
    DIGIT = 304,
    ID = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 96 "spl.y" /* yacc.c:1909  */

    int iVal;
    TERNARY_TREE  tVal;

#line 110 "spl.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SPL_TAB_H_INCLUDED  */
