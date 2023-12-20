%{
#include <stdio.h>
int yylex();
void yyerror();
%}

%token NUMBER;
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
RESULT   :  E           {printf("%d",$$);}
E        :  E'*'E       {$$ = $1*$3;}
         |  E'/'E       {$$ = $1/$3;}
         |  E'-'E       {$$ = $1-$3;}
         |  E'+'E       {$$ = $1+$3;}
         |  '('E')'     {$$ = $2;}
         |  NUMBER      {$$ = $1;}
%%

void main()
{
   printf("\nEnter an arithematic expression :\n");
   yyparse();
}

void yyerror()
{
   printf("ERROR");
}