%{
#include <stdio.h>
void yyerror();
int yylex();
%}

%token IDENTIFIER

%%
E   :   IDENTIFIER;
%%

void main()
{
    printf("Enter a valid identifier: ");
    yyparse();
    printf("Valid identifier\n");
}

void yyerror()
{
    printf("Invalid identifier\n");
}