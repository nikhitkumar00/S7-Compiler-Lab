#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	// File pointer for input file
	FILE *input;

	// Variables to track line number, token count, index, flag, and character
	int lineNumber = 1;
	int tokenCount = 0;
	int i, flag;
	char ch, lexeme[20];

	// Open the input file in read mode
	input = fopen("input.c", "r");

	// Array to store keywords
	char keywords[30][30] = {"int", "main", "if", "else", "do", "while", "include", "stdio", "void", "printf", "scanf"};

	// Display header for output
	printf("Line \t Lexeme \t Token\n\n");

	// Read characters until EOF
	while ((ch = fgetc(input)) != EOF)
	{
		i = 0;
		flag = 0;

		// Check for operators
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			printf("%d\t%c\t\tOperator\n", lineNumber, ch);
			tokenCount++;
		}
		// Check for special symbols
		else if (ch == ';' || ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == '?' || ch == '@' || ch == '!' || ch == '%')
		{
			printf("%d\t%c\t\tSpecial symbol\n", lineNumber, ch);
			tokenCount++;
		}
		// Check for digits
		else if (isdigit(ch))
		{
			printf("%d\t%c\t\tDigit\n", lineNumber, ch);
			tokenCount++;
		}
		// Check for identifiers and keywords
		else if (isalpha(ch))
		{
			lexeme[i] = ch;
			i++;

			// Read characters until a non-alphanumeric character or space is encountered
			while (isalnum(ch = fgetc(input)) && ch != ' ')
			{
				lexeme[i] = ch;
				i++;
			}

			// Null-terminate the lexeme
			lexeme[i] = '\0';

			// Check if the lexeme is a keyword
			for (int j = 0; j < 30; j++)
			{
				if (strcmp(lexeme, keywords[j]) == 0)
				{
					flag = 1;
					break;
				}
			}

			// Print the token based on the flag
			if (flag == 1)
			{
				printf("%d\t%s\t\tKeyword\n", lineNumber, lexeme);
				tokenCount++;
			}
			else
			{
				printf("%d\t%s\t\tIdentifier\n", lineNumber, lexeme);
				tokenCount++;
			}

			// Unget the non-alphanumeric character
			ungetc(ch, input);
		}
		// Check for newline character
		else if (ch == '\n')
		{
			lineNumber++;
		}
	}

	// Display total lines and total tokens
	printf("\nTotal Lines: %d\n", lineNumber - 1); // Subtract 1 for EOF
	printf("Total Tokens: %d\n", tokenCount);

	// Close the input file
	fclose(input);

	// Return 0 to indicate successful execution
	return 0;
}
