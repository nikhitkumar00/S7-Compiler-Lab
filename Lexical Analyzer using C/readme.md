# Lexical Analyzer using C Code

## Overview
This C program appears to be a simple lexical analyzer that reads a C source file ("input.c") and identifies tokens such as operators, special symbols, digits, keywords, and identifiers. The program uses basic file I/O and character manipulation to achieve lexical analysis.

## Code Breakdown

### Header Files
```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>
```
These are standard C library header files. `<stdio.h>` is included for file I/O operations, `<ctype.h>` for character classification functions, and `<string.h>` for string manipulation functions.

### Main Function
```c
int main()
{
    // Declarations
    FILE *input;
    int l = 1;  // Line number
    int t = 0;  // Token count
    int j = 0;
    int i, flag;
    char ch, str[20];  // Temporary storage for lexemes

    // Open the input file
    input = fopen("input.c", "r");

    // Array of C keywords
    char keyword[30][30] = {"int", "main", "if", "else", "do", "while", "include", "stdio", "void", "printf", "scanf"};

    printf("Lexeme \t\t Token\n\n");

    // Loop through the input file
    while (!feof(input))
    {
        i = 0;
        flag = 0;
        ch = fgetc(input);

        // Check for operators
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            printf("%c\t\tOperator\n", ch);
            t++;
        }
        // Check for special symbols
        else if (ch == ';' || ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == '?' || ch == '@' || ch == '!' || ch == '%')
        {
            printf("%c\t\tSpecial symbol\n", ch);
            t++;
        }
        // Check for digits
        else if (isdigit(ch))
        {
            printf("%c\t\tDigit\n", ch);
            t++;
        }
        // Check for identifiers and keywords
        else if (isalpha(ch))
        {
            str[i] = ch;
            i++;
            ch = fgetc(input);

            while (isalnum(ch) && ch != ' ')
            {
                str[i] = ch;
                i++;
                ch = fgetc(input);
            }

            str[i] = '\0';

            // Check if the identifier is a keyword
            for (j = 0; j < 30; j++)
            {
                if (strcmp(str, keyword[j]) == 0)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1)
            {
                printf("%s\t\tKeyword\n", str);
                t++;
            }
            else
            {
                printf("%s\t\tIdentifier\n", str);
                t++;
            }
        }
        // Check for newline character
        else if (ch == '\n')
        {
            l++;
        }
    }

    // Close the input file
    fclose(input);

    return 0;
}
```

### Explanation

- The program uses a `while` loop to iterate through each character in the input file until the end of the file is reached (`feof` function).
- It checks each character for different categories: operators, special symbols, digits, and identifiers/keywords.
- The program maintains a count of tokens (`t`) and line numbers (`l`).
- The array `keyword` stores C keywords, and the program compares identifiers against this array to determine if they are keywords.
- The output displays the lexeme and its corresponding token.

### Example Usage
Suppose the "input.c" file contains the following code:
```c
#include <stdio.h>

int main() {
    int num = 42;
    printf("Hello, World!\n");
    return 0;
}
```
Running this code through the provided lexical analyzer would produce output messages for each recognized token, as specified in the rules.

Note: This code does basic lexical analysis and has some limitations. It may not handle all cases correctly, such as multi-line comments, preprocessor directives, or complex identifier names. Additionally, it assumes the input file is well-formed and does not perform error checking.