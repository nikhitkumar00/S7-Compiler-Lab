%%
[0-9]+      { printf("\nDigit\t %s\n", yytext); }
[a-zA-Z]+   { printf("Character\t %s\n", yytext); }
%%

void main() {
    yylex();
}
