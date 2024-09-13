%{
    char *yylval;
    #include <string.h>
%}
%%
\"[^"\n]*["\n] {
        yylval = strdup(yytext+1);
        if (yylval[yyleng-2] != '"')
            warning("improperly terminated string");
        else
            yylval[yyleng-2] = 0;
        printf("found '%s'\n", yylval);
    }
	
%%