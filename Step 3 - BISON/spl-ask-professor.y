%{
%}

%start program

%union{
}

%token	FULLSTOP COMMA COLON SEMICOLON ASSIGN BRA KET EQUAL NOT_EQUAL LESS_THAN GREATER_THAN LESS_THAN_OR_EQUAL GREATER_THAN_OR_EQUAL PLUS MINUS TIMES DIVIDE APOSTROPHE ENDP DECLARATIONS
		CODE OF TYPE IF THEN ENDIF ELSE DO WHILE ENDDO ENDWHILE FOR IS BY TO ENDFOR WRITE READ NEWLINE NOT AND OR
%token	DIGIT CHARACTER INTEGER REAL IDENTIFIER

%%

program : IDENTIFIER COLON block ENDP IDENTIFIER FULLSTOP ;

block : DECLARATIONS declaration_block CODE statement_list | CODE statement_list ;

identifier_list : IDENTIFIER | identifier_list COMMA IDENTIFIER ;

declaration_block **semi as ";" instead of SEMICOLON?** : identifier_list OF TYPE type ";" | declaration_block identifier_list OF TYPE type ";" ;

type : CHARACTER | INTEGER | REAL ;

statement_list : statement | statement_list ";" statement ;

statment : assignment_statement | if_statement | do_statement | while_statement | for_statement | write_statement | read_statement ;

assignment_statement : expression ASSIGN IDENTIFIER ;

if_statement : IF conditional THEN statement_list ENDIF | IF conditional THEN statement_list ELSE statement_list ENDIF ;

do_statement : DO statement_list WHILE conditional ENDDO ;

while_statement : WHILE conditional DO statement_list ENDWHILE ;

for_statement : FOR IDENTIFIER IS expression BY expression TO expression DO statement_list ENDFOR ;

write_statement : WRITE BRA output_list KET | NEWLINE ;

read_statement : READ BRA IDENTIFIER KET ;

output_list : value | output_list COMMA value ;

logical_operator : AND | OR ;

basic_conditional : expression comparator expression | NOT basic_conditional ;

conditional : basic_conditional | conditional logical_operator basic_conditional ;

comparator : EQUAL | NOT_EQUAL | LESS_THAN | GREATER_THAN | LESS_THAN_OR_EQUAL | GREATER_THAN_OR_EQUAL ;

expression : term | expression PLUS term | expression MINUS term ;

term : value | term TIMES value | term DIVIDE value ;

value : IDENTIFIER | constant | BRA expression KET ;

constant : number_constant | character_constant ;

character_constant **clarify about the apostrophe's here and lex file** : APOSTROPHE CHARACTER APOSTROPHE ;

number_constant **allowed to have 2 decimal places?** : digit | FULLSTOP digit | number_constant digit | number_constant FULLSTOP digit ;

%%

#include "lex.yy.c"