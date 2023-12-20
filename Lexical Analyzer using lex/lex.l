%{
	FILE *fp;
%}

digit			[0-9]+
header			[\t]*"#include <"[a-z]+".h>"
bracket			[\t]*"{"|"}"|"["|"]"|"("|")"
whitespace  	[\n]
formatspecifier	[\t]*"%"[a-zA-Z]
comma			[,]
quote			[\t]*"\""
terminator		[\t]*";"
keyword			[\t]*"int"|"float"|"char"|"void"|"if"|"else"|"for"|"while"|"do"|"printf"|"scanf"
main			[\t]*"main()"
identifier		[\t]*[_a-zA-Z]+[_0-9a-zA-Z]*
operator		[+\-*/%=]
comparator		[\t]*"=="|"!="|"<="|">="|"<"|">"

%%
{digit}				printf("\nDigit \t\t\t%s", yytext);
{header}			printf("\nHeader \t\t\t%s", yytext);
{keyword}			printf("\nKeyword \t\t%s", yytext);
{main}				printf("\nMain Function \t\t%s", yytext);
{identifier}		printf("\nIdentifier \t\t%s", yytext);
{operator}			printf("\nOperator \t\t%s", yytext);
{comparator} 		printf("\nComparator \t\t%s", yytext);
{bracket} 			printf("\nBracket \t\t%s", yytext);
{terminator} 		printf("\nTerminator \t\t%s", yytext);
{quote} 			printf("\nQuote \t\t\t%s", yytext);
{formatspecifier} 	printf("\nFormat Specifier \t%s", yytext);
{whitespace} 		{};
{comma} 			printf("\nComma \t\t\t%s", yytext);
%%

void main()
{
	fp = fopen("input.c", "r");
	if (fp != NULL)
	{
		yyin = fp;
		yylex();
	}
}