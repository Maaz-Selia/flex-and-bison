%{

#include <stdio.h>
#include <stdlib.h>

int yylex (void);
void yyerror (char *);

/* 
   Some constants.
*/

  /* These constants are used later in the code */
#define SYMTABSIZE     50
#define IDLENGTH       15
#define NOTHING        -1
#define INDENTOFFSET    2

enum ParseTreeNodeType { PROGRAM, BLOCK, IDENTIFIER, IDENTIFIER_LIST, DECLARATION_BLOCK, TYPE_T, STATEMENT_LIST, STATEMENT, ASSIGNMENT_STATEMENT, IF_STATEMENT, DO_STATEMENT, 
						WHILE_STATEMENT, FOR_CONDITIONS, FOR_STATEMENT, WRITE_STATEMENT, READ_STATEMENT, OUTPUT_LIST, LOGICAL_OPERATOR, BASIC_CONDITIONAL, CONDITIONAL, COMPARATOR, EXPRESSION, PLUS_EXPRESSION, 
						MINUS_EXPRESSION, TERM, TIMES_TERM, DIVIDE_TERM, VALUE, IDENTIFIER_VALUE, CONSTANT_VALUE, CONSTANT, CHARACTER_CONSTANT, NUMBER_CONSTANT} ;

char *NodeName[] = { "PROGRAM", "BLOCK", "IDENTIFIER", "IDENTIFIER_LIST", "DECLARATION_BLOCK", "TYPE_T", "STATEMENT_LIST", "STATEMENT", "ASSIGNMENT_STATEMENT", "IF_STATEMENT", 
					"DO_STATEMENT", "WHILE_STATEMENT", "FOR_CONDITIONS", "FOR_STATEMENT", "WRITE_STATEMENT", "READ_STATEMENT", "OUTPUT_LIST", "LOGICAL_OPERATOR", "BASIC_CONDITIONAL", "CONDITIONAL", 
					"COMPARATOR", "EXPRESSION", "PLUS_EXPRESSION", "MINUS_EXPRESSION", "TERM", "TIMES_TERM", "DIVIDE_TERM", "VALUE", "IDENTIFIER_VALUE", "CONSTANT_VALUE", 
					"CONSTANT", "CHARACTER_CONSTANT", "NUMBER_CONSTANT"} ;

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

/* ------------- statement trackerS ------------------------------ */

int firstRead = 1;
int insideStat = 0;

/* ------------- parse tree definition --------------------------- */

struct treeNode {
    int  item;
    int  nodeIdentifier;
    struct treeNode *first;
    struct treeNode *second;
    struct treeNode *third;
  };

typedef  struct treeNode TREE_NODE;
typedef  TREE_NODE        *TERNARY_TREE;

/* ------------- forward declarations --------------------------- */

TERNARY_TREE create_node(int,int,TERNARY_TREE,TERNARY_TREE,TERNARY_TREE);
#ifdef DEBUG
void PrintTree(TERNARY_TREE, int);
#endif
void codeGenerate(TERNARY_TREE);

/* ------------- symbol table definition --------------------------- */

struct symTabNode {
    char identifier[IDLENGTH];
};

typedef  struct symTabNode SYMTABNODE;
typedef  SYMTABNODE        *SYMTABNODEPTR;

SYMTABNODEPTR  symTab[SYMTABSIZE]; 

int currentSymTabSize = 0;

%}

/****************/
/* Start symbol */
/****************/

%start  program

/**********************/
/* Action value types */
/**********************/

%union {
    int iVal;
    TERNARY_TREE  tVal;
}

%token	FULLSTOP COMMA COLON SEMICOLON ASSIGN BRA KET EQUAL NOT_EQUAL LESS_THAN GREATER_THAN LESS_THAN_OR_EQUAL GREATER_THAN_OR_EQUAL PLUS MINUS TIMES DIVIDE 
		APOSTROPHE ENDP DECLARATIONS CODE OF TYPE CHARACTER INTEGER REAL IF THEN ENDIF ELSE DO WHILE ENDDO ENDWHILE FOR IS BY TO ENDFOR WRITE READ NEWLINE NOT AND OR
%token<iVal> LETTER DIGIT ID
%type<tVal> program block identifier identifier_list declaration_block type statement_list statement assignment_statement if_statement do_statement while_statement for_conditions for_statement write_statement 
			read_statement output_list logical_operator basic_conditional conditional comparator expression term value constant character_constant number_constant
							
%%

program	: identifier COLON block ENDP identifier FULLSTOP
		{
			TERNARY_TREE ParseTree;
			ParseTree = create_node(NOTHING, PROGRAM, $1, $3, $5);
			#ifdef DEBUG
				PrintTree(ParseTree, 0);
			#endif
			codeGenerate(ParseTree);
		};

block : DECLARATIONS declaration_block CODE statement_list
		{
			$$ = create_node(NOTHING, BLOCK, $2, $4, NULL);
		}
		| CODE statement_list
		{
			$$ = create_node(NOTHING, BLOCK, $2, NULL, NULL);
		};

identifier : ID 
			{
				$$ = create_node($1, IDENTIFIER, NULL, NULL, NULL);
			}
			;

identifier_list : identifier
				{
					$$ = create_node(NOTHING, IDENTIFIER_LIST, $1, NULL, NULL);
				}
				| identifier_list COMMA identifier
				{
					$$ = create_node(NOTHING, IDENTIFIER_LIST, $1, $3, NULL);
				};

declaration_block : identifier_list OF TYPE type SEMICOLON
					{
						$$ = create_node(NOTHING, DECLARATION_BLOCK, $1, $4, NULL);
					}
					| declaration_block identifier_list OF TYPE type SEMICOLON
					{
						$$ = create_node(NOTHING, DECLARATION_BLOCK, $1, $2, $5);
					};

type : CHARACTER
		{
			$$ =  create_node(CHARACTER, TYPE_T, NULL, NULL, NULL);
		}
		| INTEGER
		{
			$$ =  create_node(INTEGER, TYPE_T, NULL, NULL, NULL);
		}
		| REAL
		{
			$$ =  create_node(REAL, TYPE_T, NULL, NULL, NULL);
		};

statement_list : statement
				{
					$$ = create_node(NOTHING, STATEMENT_LIST, $1, NULL, NULL);
				}
				| statement_list SEMICOLON statement
				{
					$$ = create_node(NOTHING, STATEMENT_LIST, $1, $3, NULL);
				};

statement : assignment_statement
			{
				$$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);
			}
			| if_statement
			{
				$$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);
			}
			| do_statement
			{
				$$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);
			}
			| while_statement
			{
				$$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);
			}
			| for_statement
			{
				$$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);
			}
			| write_statement
			{
				$$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);
			}
			| read_statement
			{
				$$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);
			};

assignment_statement : expression ASSIGN identifier 
						{
							$$ = create_node(NOTHING, ASSIGNMENT_STATEMENT, $1, $3, NULL);
						};

if_statement : IF conditional THEN statement_list ENDIF 
				{
					$$ = create_node(NOTHING, IF_STATEMENT, $2, $4, NULL);
				}
				| IF conditional THEN statement_list ELSE statement_list ENDIF
				{
					$$ = create_node(NOTHING, IF_STATEMENT, $2, $4, $6);
				};

do_statement : DO statement_list WHILE conditional ENDDO 
				{ 
					$$ = create_node(NOTHING, DO_STATEMENT, $2, $4, NULL);
				};

while_statement : WHILE conditional DO statement_list ENDWHILE
				{
					$$ = create_node(NOTHING, WHILE_STATEMENT, $2, $4, NULL);
				};

for_conditions : IS expression BY expression TO expression
				{
					$$ = create_node(NOTHING, FOR_CONDITIONS, $2, $4, $6);
				}
				;

for_statement : FOR identifier for_conditions DO statement_list ENDFOR 
				{
					$$ = create_node(NOTHING, FOR_STATEMENT, $2, $3, $5);
				};

write_statement : WRITE BRA output_list KET 
				{
					$$ = create_node(NOTHING, WRITE_STATEMENT, $3, NULL, NULL);
				}
				| NEWLINE 
				{
					$$ = create_node(NEWLINE, WRITE_STATEMENT, NULL, NULL, NULL);
				};

read_statement : READ BRA identifier KET
				{
					$$ = create_node(NOTHING, READ_STATEMENT, $3, NULL, NULL);
				};

output_list : value 
				{
					$$ = create_node(NOTHING, OUTPUT_LIST, $1, NULL, NULL);
				}
				| output_list COMMA value 
				{
					$$ = create_node(NOTHING, OUTPUT_LIST, $1, $3, NULL);
				};

logical_operator : AND 
					{
						$$ = create_node(AND, LOGICAL_OPERATOR, NULL, NULL, NULL);
					}
					| OR 
					{
						$$ = create_node(OR, LOGICAL_OPERATOR, NULL, NULL, NULL);
					};

basic_conditional : expression comparator expression 
					{
						$$ = create_node(NOTHING, BASIC_CONDITIONAL, $1, $2, $3);
					}
					| NOT basic_conditional 
					{
						$$ = create_node(NOTHING, BASIC_CONDITIONAL, $2, NULL, NULL);
					};

conditional : basic_conditional 
				{
					$$ = create_node(NOTHING, CONDITIONAL, $1, NULL, NULL);
				}
				| conditional logical_operator basic_conditional 
				{
					$$ = create_node(NOTHING, CONDITIONAL, $1, $2, $3);
				};

comparator : EQUAL 
			{
				$$ = create_node(EQUAL, COMPARATOR, NULL, NULL, NULL);
			}
			| NOT_EQUAL
			{
				$$ = create_node(NOT_EQUAL, COMPARATOR, NULL, NULL, NULL);
			}
			| LESS_THAN
			{
				$$ = create_node(LESS_THAN, COMPARATOR, NULL, NULL, NULL);
			}
			| GREATER_THAN
			{
				$$ = create_node(GREATER_THAN, COMPARATOR, NULL, NULL, NULL);
			}
			| LESS_THAN_OR_EQUAL
			{
				$$ = create_node(LESS_THAN_OR_EQUAL, COMPARATOR, NULL, NULL, NULL);
			}
			| GREATER_THAN_OR_EQUAL
			{
				$$ = create_node(GREATER_THAN_OR_EQUAL, COMPARATOR, NULL, NULL, NULL);
			};

expression : term 
			{
				$$ = create_node(NOTHING, EXPRESSION, $1, NULL, NULL);
			}
			| expression term /* Added */
			{
				$$ = create_node(NOTHING, EXPRESSION, $1, $2, NULL);
			}
			| expression PLUS term
			{
				$$ = create_node(NOTHING, PLUS_EXPRESSION, $1, $3, NULL);
			}
			| expression MINUS term 
			{
				$$ = create_node(NOTHING, MINUS_EXPRESSION, $1, $3, NULL);
			};

term : value 
		{
			$$ = create_node(NOTHING, TERM, $1, NULL, NULL);
		}
		| term TIMES value
		{
			$$ = create_node(NOTHING, TIMES_TERM, $1, $3, NULL);
		}
		| term DIVIDE value
		{
			$$ = create_node(NOTHING, DIVIDE_TERM, $1, $3, NULL);
		};

value : identifier 
		{
			$$ = create_node(NOTHING, IDENTIFIER_VALUE, $1, NULL, NULL);
		}
		| constant
		{
			$$ = create_node(NOTHING, CONSTANT_VALUE, $1, NULL, NULL);
		}
		| BRA expression KET
		{
			$$ = create_node(NOTHING, VALUE, $2, NULL, NULL);
		};

constant : number_constant 
			{
				$$ = create_node(NOTHING, CONSTANT, $1, NULL, NULL);
			}
			| character_constant
			{
				$$ = create_node(NOTHING, CONSTANT, $1, NULL, NULL);
			};

character_constant : LETTER
					{
						$$ = create_node($1, CHARACTER_CONSTANT, NULL, NULL, NULL);
					}
					;

number_constant : DIGIT
					{
						$$ = create_node($1, NUMBER_CONSTANT, NULL, NULL, NULL);
					}
					;

%%

TERNARY_TREE create_node(int ival, int case_identifier, TERNARY_TREE p1,
			 TERNARY_TREE  p2, TERNARY_TREE  p3)
{
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    t->item = ival;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;
    return (t);
}

#ifdef DEBUG
void PrintTree(TERNARY_TREE t, int indent)
{
	int i;
	if (t == NULL) return;
	for (i=indent; i; i--) printf(" ");

	if (t->nodeIdentifier == NUMBER_CONSTANT)
			printf("Number: %d ", t->item);
	else if (t->nodeIdentifier == IDENTIFIER) /// || t->nodeIdentifier == ASSIGNMENT_STATEMENT) 
		if (t->item >= 0 && t->item < SYMTABSIZE)
			printf("Identifier: %s ", symTab[t->item]->identifier);
		else 
			printf("Unknown Identifier: %d ", t->item);
			
	if(t->item != NOTHING) printf(" Item: %d ", t->item);
	if (t->nodeIdentifier < 0 || t->nodeIdentifier > sizeof(NodeName))
		printf("Unknown nodeIdentifier: %d\n", t->nodeIdentifier);
	else
	{
		printf("%s\n", NodeName[t->nodeIdentifier]);
		PrintTree(t->first, indent+3);
		PrintTree(t->second, indent+3);
		PrintTree(t->third, indent+3);		
	}
}
#endif

void codeGenerate(TERNARY_TREE t)
{
	if (t == NULL) return;
	
	switch(t->nodeIdentifier)
	{
		case(PROGRAM) :
		
			printf("#include <stdio.h>\n");
			printf("#include <stddef.h>\n");
			printf("#include <stdlib.h>\n");
			/*printf("#include <stdint.h>\n");*/
			printf("\n");
			printf("#define typename(x) _Generic((x), int: \"int\", float: \"float\", default: \"other\")\n");
			printf("#define print_any(X) _Generic((X), int: print_int, char *: print_pchar, char: print_char, float: print_float)(X)\n");
			printf("\nint print_int(int i) { return printf(\"%%d\\n\", i); }\n");
			printf("\nint print_float(float f) { return printf(\"%%f\\n\", f); }\n");
			printf("\nint print_pchar(char *c) { return printf(\"%%s\\n\", c); }\n");
			printf("\nint print_char(char c) { return printf(\"%%s\\n\", c); }\n");
			printf("\nint main(void) {\n\n");
			codeGenerate(t->second);
			printf("\n}\n");
			
			return;
			
		case(BLOCK) :
		
			codeGenerate(t->first);
			if(t->second != NULL)
				codeGenerate(t->second);
			
			return;
		
		case(IDENTIFIER) :		
			
			if (t->item >= 0 && t->item < SYMTABSIZE)
				printf("%s", symTab[t->item]->identifier);			
			
			return;
			
		case(IDENTIFIER_LIST) :
			
			if(t->second != NULL) {		
				codeGenerate(t->first);
				printf(", ");
				codeGenerate(t->second);
			} 
			else {
				codeGenerate(t->first);
			}
			
			return;
			
		case(DECLARATION_BLOCK) :
			
			if(t->third != NULL) {
				codeGenerate(t->first);
				codeGenerate(t->third);
				printf(" ");
				codeGenerate(t->second);
				printf(";\n\n");
			}
			else {
				codeGenerate(t->second);
				printf(" ");
				codeGenerate(t->first);
				printf(";\n\n");
			}			
			
			return;
			
		case(TYPE_T) :
			
			if(t->item == CHARACTER)
				printf("\tchar");
			else if(t->item == INTEGER)
				printf("\tint");
			else if(t->item == REAL)
				printf("\tfloat");
			
			return;
			
		case(STATEMENT_LIST) :
		
			if(t->second != NULL) {
				codeGenerate(t->first);
				if(insideStat == 1)
					printf("\t");
				codeGenerate(t->second);
			}
			else {
				codeGenerate(t->first);
			}
			return;
			
		case(STATEMENT) :
			
			codeGenerate(t->first);
		
			return;
			
		case(ASSIGNMENT_STATEMENT) :
			
			printf("\t");
			codeGenerate(t->second);
			printf(" = ");
			codeGenerate(t->first);
			printf(";\n");
			
			return;
			
		case(IF_STATEMENT) :
			
			if(t->third != NULL) {			
				printf("\n\tif (");
				codeGenerate(t->first);
				printf(") {\n\t");
				codeGenerate(t->second);
				printf("\t}\n\telse {\n\t");
				codeGenerate(t->third);
				printf("\t}\n\n");
			}
			else {
				printf("\n\tif (");
				codeGenerate(t->first);
				printf(") {\n\t");
				codeGenerate(t->second);
				printf("\t}\n\n");
			}
			
			return;
			
		case(DO_STATEMENT) :
		
			printf("\n\tdo {\n\t");
			codeGenerate(t->first);
			printf("\t} while (");
			codeGenerate(t->second);
			printf(");\n\n");
			
			return;
			
		case(WHILE_STATEMENT) :
		
			printf("\n\twhile (");
			codeGenerate(t->first);
			printf(") {\n\t");
			codeGenerate(t->second);
			printf("\t}\n\n");
			
			return;
			
		case(FOR_CONDITIONS) :
			
			/*printf("; ");*/
			codeGenerate(t->first);
			printf("; ");
			codeGenerate(t->second);
			printf("; ");
			codeGenerate(t->third);
			
			return;
			
		case(FOR_STATEMENT) :
			
			insideStat = 1;
			
			printf("\n\tfor (");
			/*codeGenerate(t->first);*/
			codeGenerate(t->second);
			printf(") {\n\t");
			codeGenerate(t->third);
			printf("\t}\n\n");

			insideStat = 0;
			
			return;
			
		case(WRITE_STATEMENT) :
			
			if(t->item == NEWLINE) {
				printf("\tprintf(\"\\n\");\n");
			}
			else {
				printf("\t");
				codeGenerate(t->first);
			}			
			
			return;
			
		case(READ_STATEMENT) :
			
			if(firstRead == 1) {
				printf("\tchar *str;\n");
				firstRead = 0;
			}
	
			printf("\tscanf(\"%%s\", str);\n");
			
			
			/* ---------- Type introspection ---------- */
			
			printf("\tif(typename(");
			codeGenerate(t->first);
			printf(") == \"other\")\n\t\t");
			codeGenerate(t->first);
			printf(" = *str;\n");
			printf("\telse if(typename(");
			codeGenerate(t->first);
			printf(") == \"int\")\n\t\t");
			codeGenerate(t->first);
			printf(" = atoi(str);\n");
			printf("\telse if(typename(");
			codeGenerate(t->first);
			printf(") == \"float\")\n\t\t");
			codeGenerate(t->first);
			printf(" = atof(str);\n\n");
			
			return;
			
		case(OUTPUT_LIST) :
		
			if(t->second != NULL) {
				codeGenerate(t->first);
				printf("\tprint_any(");
				codeGenerate(t->second);
				printf(");\n");
			}
			else {
				printf("print_any(");
				codeGenerate(t->first);
				printf(");\n");
			}
			return;
			
		case(LOGICAL_OPERATOR) :
		
			if(t->item == AND)
				printf(" && ");
			if(t->item == OR)
				printf(" || ");
			
			return;
			
		case(BASIC_CONDITIONAL) :
		
			if(t->second != NULL) {
				codeGenerate(t->first);
				codeGenerate(t->second);
				codeGenerate(t->third);
				return;
			}
			printf("!");
			codeGenerate(t->first);
			
			return;
			
		case(CONDITIONAL) :
		
			if(t->second == NULL)
				codeGenerate(t->first);
			else {
				codeGenerate(t->first);
				codeGenerate(t->second);
				codeGenerate(t->third);
			}
			
			return;
			
		case(COMPARATOR) :
		
			if (t->item == EQUAL)
				printf(" == ");
			else if (t->item == NOT_EQUAL)
				printf(" != ");
			else if (t->item == LESS_THAN)
				printf(" < ");
			else if (t->item == GREATER_THAN)
				printf(" > ");
			else if (t->item == LESS_THAN_OR_EQUAL)
				printf(" <= ");
			else if (t->item == GREATER_THAN_OR_EQUAL)
				printf(" >= ");
				
			return;
			
		case(EXPRESSION) :
		
			if(t->second != NULL) {
				codeGenerate(t->first);
				codeGenerate(t->second);
			}
			else {
				codeGenerate(t->first);
			}
			
			return;
			
		case(PLUS_EXPRESSION) :
		
			codeGenerate(t->first);
			printf(" + ");
			codeGenerate(t->second);
			
			return;
			
		case(MINUS_EXPRESSION) :
		
			codeGenerate(t->first);
			printf(" - ");
			codeGenerate(t->second);
			
			return;
			
		case(TERM) :
			
			codeGenerate(t->first);
			
			return;
			
		case(TIMES_TERM) :
		
			codeGenerate(t->first);
			printf(" * ");
			codeGenerate(t->second);
			
			return;
			
		case(DIVIDE_TERM) :
		
			codeGenerate(t->first);
			printf(" / ");
			codeGenerate(t->second);
			
			return;
			
		case(VALUE) :
		
			printf("(");
			codeGenerate(t->first);
			printf(")");
			
			return;
			
		case(IDENTIFIER_VALUE) :
			
			codeGenerate(t->first);
			
			return;
			
		case(CONSTANT_VALUE) :
			
			codeGenerate(t->first);
			
			return;
			
		case(CONSTANT) :
			
			codeGenerate(t->first);
			
			return;
			
		case(CHARACTER_CONSTANT) :
			
			;	
			char *str;
			str = symTab[t->item]->identifier;
			printf("\"");
			printf("%c", str[1]);
			printf("\"");
			
			return;
			
		case(NUMBER_CONSTANT) :
		
			if (t->item >= 0 && t->item < SYMTABSIZE) {
				printf("%s", symTab[t->item]->identifier);
			}
			
			return;		

	}
	codeGenerate(t->first);
	codeGenerate(t->second);
	codeGenerate(t->third);
}

#include "lex.yy.c"
