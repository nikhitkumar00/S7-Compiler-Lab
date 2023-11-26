digit [0-9]+
character [a-zA-Z]+

%%
{digit}         printf("\nDigit\t %s\n", yytext);
{character}     printf("Character\t %s\n", yytext);
%%

void main() {
    yylex();
}
