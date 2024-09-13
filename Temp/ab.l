%{
#ifdef PRINT
#define TOKEN(t) printf("Token: " #t "\n");
#define ID_TOKEN(t) printf("Token: %s " #t "\n", yytext);
#define LETTER_TOKEN(t) printf("Token: %s " #t "\n", yytext);
#define DIGIT_TOKEN(t) printf("Token: %s " #t "\n", yytext);
#else
#define TOKEN(t) return(t);
#define ID_TOKEN(t) yylval.iVal = installId(yytext); return(t);
#define LETTER_TOKEN(t) yylval.iVal = installId(yytext); return(t);
#define DIGIT_TOKEN(t) yylval.iVal = installId(yytext); return(t);

/* Declare Symbol Table Type and Array as imported types */
#include <string.h>
extern SYMTABNODEPTR symTab[SYMTABSIZE];
extern int currentSymTabSize;
int installId(char *);
#endif

%}

DELIM			[ \t\r\n]
WS              {DELIM}+
REAL_Def		-?[0-9]*\.[0-9]+
INTEGER_Def		-?[0-9]+
DIGIT			({REAL_Def}|{INTEGER_Def})
LETTER			'[a-zA-Z]'
ID				[a-zA-Z]([a-zA-Z]|[0-9])*

%%

{WS}			; /* Skip */
"."       		TOKEN(FULLSTOP)
"," 			TOKEN(COMMA)
":" 			TOKEN(COLON)
";" 			TOKEN(SEMICOLON)
"->" 			TOKEN(ASSIGN)
"(" 			TOKEN(BRA)
")" 			TOKEN(KET)
"=" 			TOKEN(EQUAL)
"<>" 			TOKEN(NOT_EQUAL)
"<" 			TOKEN(LESS_THAN)
">" 			TOKEN(GREATER_THAN)
"<=" 			TOKEN(LESS_THAN_OR_EQUAL)
">=" 			TOKEN(GREATER_THAN_OR_EQUAL)
"+" 			TOKEN(PLUS)
"-" 			TOKEN(MINUS)
"*" 			TOKEN(TIMES)
"/" 			TOKEN(DIVIDE)
"'"				TOKEN(APOSTROPHE)
ENDP 			TOKEN(ENDP)
DECLARATIONS 	TOKEN(DECLARATIONS)
CODE 			TOKEN(CODE)
OF 				TOKEN(OF)
TYPE 			TOKEN(TYPE)
CHARACTER		TOKEN(CHARACTER)
INTEGER 		TOKEN(INTEGER)
REAL 			TOKEN(REAL)
IF 				TOKEN(IF)
THEN 			TOKEN(THEN)
ENDIF			TOKEN(ENDIF)
ELSE 			TOKEN(ELSE)
DO 				TOKEN(DO)
WHILE 			TOKEN(WHILE)
ENDDO			TOKEN(ENDDO)
ENDWHILE 		TOKEN(ENDWHILE)
FOR 			TOKEN(FOR)
IS 				TOKEN(IS)
BY				TOKEN(BY)
TO 				TOKEN(TO)
ENDFOR 			TOKEN(ENDFOR)
WRITE 			TOKEN(WRITE)
READ 			TOKEN(READ)
NEWLINE 		TOKEN(NEWLINE)
NOT 			TOKEN(NOT)
AND 			TOKEN(AND)
OR 				TOKEN(OR)
{LETTER}		LETTER_TOKEN(LETTER)
{DIGIT}			DIGIT_TOKEN(DIGIT)
{ID}			ID_TOKEN(ID)
.				printf("Error: Unexpected symbol in bagging area. %s (%d)\n", yytext, yytext[0]);

%%

#ifndef PRINT

SYMTABNODEPTR newSymTabNode()
{
    return ((SYMTABNODEPTR)malloc(sizeof(SYMTABNODE)));
}

int lookup(char *s)
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE];
    extern int currentSymTabSize;
    int i;

    for(i=0; i<currentSymTabSize; i++)
    {
        if(strncmp(s,symTab[i]->identifier,IDLENGTH) == 0)
        {
            return (i);
        }
    }
    return (-1);    
}

/* Look up an identifier in the symbol table, if its there return
   its index.  If its not there, put it in the end position,
   as long as the table isn't full, and return its index.
*/

int installId(char *id) 
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE]; 
    extern int currentSymTabSize;
    int index;

    index = lookup(id);
    if (index >= 0)
    {
        return (index);
    }
    else 
       if (currentSymTabSize >= SYMTABSIZE) 
          /* SYMTAB is full */
          return (NOTHING) ;
    else
    {
       symTab[currentSymTabSize] = newSymTabNode();
       /* Recommended code for preventing buffer overrun on bounded strings */
       strncpy(symTab[currentSymTabSize]->identifier,id,IDLENGTH);
       symTab[currentSymTabSize]->identifier[IDLENGTH-1] = '\0';
       return(currentSymTabSize++);
    }
}
#endif
