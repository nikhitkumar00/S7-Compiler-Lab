%{
#include <stdio.h>
void yyerror();
int yylex();
int flag = 0;
%}

%token IDENTIFIER

%%
E:IDENTIFIER;
%%

void main()
{
    printf("Enter a valid identifier: ");
    yyparse();
    if (flag == 0)
        printf("Valid identifier\n");
}

void yyerror()
{
    printf("Invalid identifier\n");
    flag = 1;
}