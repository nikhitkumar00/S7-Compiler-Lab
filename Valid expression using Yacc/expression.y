%{
	#include<stdio.h>
	int flag=0;
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
	E:E'+'E
	|E'-'E
	|E'*'E
	|E'/'E
	|E'%'E
	|'('E')'
	|NUMBER
	;
%%

void main()
{
	printf("\nEnter Expression: ");
	yyparse();
	if(flag==0)
		printf("\nEntered expression is Valid\n\n");
}
void yyerror()
{
	printf("\nEntered expression is Invalid\n\n");
	flag=1;
}
