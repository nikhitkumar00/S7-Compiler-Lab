%{
    #include <stdio.h>
    #include "y.tab.h"
    extern int yylval;
%}

%%
[_a-zA-Z][_a-zA-Z0-9]*    {
                            yylval = atoi(yytext);
                            return IDENTIFIER;
                        }
[\t]                    ;
[\n]                    return 0;
.                       return yytext[0];
%%

int yywrap()
{
    return 0;
}