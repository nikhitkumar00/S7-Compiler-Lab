%{
	int character=0, digit=0, position=0, negative=0, special=0, whitespace=0;
%}

%%
[0-9] digit++,position++;
[a-zA-Z] character++;
[-][0-9] negative++,digit++;
[<>@#$%^&*(){}"'.;] special++;
[ \n\t] whitespace++;
%%
 
int main()
{
	yyin = fopen("input.txt","r");
	yylex();

	printf("Character count is :\t\t%d\n",character);
	printf("Digit count is :\t\t%d\n",digit);
	printf("Positive count is :\t\t%d\n",position);
	printf("Negative count is :\t\t%d\n",negative);
	printf("Special character count is :\t%d\n",special);
	printf("Whitespace count is :\t\t%d\n",whitespace);
}

int yywrap()
{
	return 1;
}
