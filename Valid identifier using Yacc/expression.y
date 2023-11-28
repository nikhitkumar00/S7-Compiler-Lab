%{
#include<stdio.h>
int flag=0;
%}

%token IDENTIFIER

%%
    E: IDENTIFIER;
%%
void main()
{
    printf("\nEnter Identifier: ");
    yyparse();
    if(flag==0)
        printf("\nEntered identifier is Valid\n\n");
}

void yyerror()
{
    printf("\nEntered identifier is Invalid\n\n");
    flag=1;
}
