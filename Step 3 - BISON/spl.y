%{
int yylex();
void yyerror(const char *s);
%}

%start program

%union{


}

%token	FULLSTOP COMMA COLON SEMICOLON ASSIGN BRA KET EQUAL NOT_EQUAL LESS_THAN GREATER_THAN LESS_THAN_OR_EQUAL GREATER_THAN_OR_EQUAL PLUS MINUS TIMES DIVIDE APOSTROPHE ENDP DECLARATIONS
		CODE OF TYPE CHARACTER INTEGER REAL IF THEN ENDIF ELSE DO WHILE ENDDO ENDWHILE FOR IS BY TO ENDFOR WRITE READ NEWLINE NOT AND OR LETTER DIGIT

%%

program : identifier COLON block ENDP identifier FULLSTOP ;

block : DECLARATIONS declaration_block CODE statement_list | CODE statement_list ;

identifier : LETTER | identifier LETTER | identifier DIGIT ;

identifier_list : identifier | identifier_list COMMA identifier ;

declaration_block : identifier_list OF TYPE type SEMICOLON | declaration_block identifier_list OF TYPE type SEMICOLON ;

type : CHARACTER | INTEGER | REAL ;

statement_list : statement | statement_list SEMICOLON statement ;

statement : assignment_statement | if_statement | do_statement | while_statement | for_statement | write_statement | read_statement ;

assignment_statement : expression ASSIGN identifier ;

if_statement : IF conditional THEN statement_list ENDIF | IF conditional THEN statement_list ELSE statement_list ENDIF ;

do_statement : DO statement_list WHILE conditional ENDDO ;

while_statement : WHILE conditional DO statement_list ENDWHILE ;

for_statement : FOR identifier IS expression BY expression TO expression DO statement_list ENDFOR ;

write_statement : WRITE BRA output_list KET | NEWLINE ;

read_statement : READ BRA identifier KET ;

output_list : value | output_list COMMA value ;

logical_operator : AND | OR ;

basic_conditional : expression comparator expression | NOT basic_conditional ;

conditional : basic_conditional | conditional logical_operator basic_conditional ;

comparator : EQUAL | NOT_EQUAL | LESS_THAN | GREATER_THAN | LESS_THAN_OR_EQUAL | GREATER_THAN_OR_EQUAL ;

expression : term | expression PLUS term | expression MINUS term ;

term : value | term TIMES value | term DIVIDE value ;

value : identifier | constant | BRA expression KET ;

constant : number_constant | character_constant ;

character_constant : APOSTROPHE LETTER APOSTROPHE ;

number_constant : MINUS DIGIT | DIGIT | FULLSTOP DIGIT | number_constant DIGIT | number_constant FULLSTOP DIGIT ;

%%

#include "lex.yy.c"
