%{
#include <stdio.h>
int yylex();
void yyerror();
int flag = 0;
%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%left '(' ')'

 %%
 ArithExpr:E {printf("Result: %d\n", $$);}
 E:E'+'E {$$ = $1 + $3;}
 |E'-'E {$$ = $1 - $3;}
 |E'*'E {$$ = $1 * $3;}
 |E'/'E {$$ = $1 / $3;}
 |'('E')' {$$ = $2;}
 |NUMBER {$$ = $1;}
 %%

 void main()
 {
    printf("Enter an expression: ");
    yyparse();
 }

 void yyerror()
 {
    printf("Syntax error\n");
    flag = 1;
 }