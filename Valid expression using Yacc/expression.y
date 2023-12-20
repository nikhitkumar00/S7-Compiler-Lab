%{
	#include<stdio.h>
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
E	:	E'+'E
	|	E'-'E
	|	E'*'E
	|	E'/'E
	|	E'%'E
	|	'('E')'
	|	NUMBER
	;
%%

void main()
{
	printf("\nEnter Expression: ");
	yyparse();
	printf("\nEntered expression is Valid\n\n");
}
void yyerror()
{
	printf("\nEntered expression is Invalid\n\n");
}
