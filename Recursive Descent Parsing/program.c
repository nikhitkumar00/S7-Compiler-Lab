#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int E();
int Edash();
int T();
int Tdash();
int F();

// Global variables
char input[20];
char *cursor;

// Constants
#define SUCCESS 1
#define FAILED 0

// Main function
void main()
{
    printf("The Grammars are :\nGrammar rule: E -> T E'\nGrammar rule: E' -> + T E' | $\nGrammar rule: T -> F T'\nGrammar rule: T' -> * F T' | $\nGrammar rule: F -> ( E ) | i\n\n");
    scanf("%s", input);
    cursor = input;

    if (E() && *cursor == '\0')
    {
        printf("\n\nPARSING COMPLETED SUCCESSFULLY\n\n");
    }
    else
    {
        printf("\n\nPARSING FAILED\n\n");
    }
}

// E -> T E'
int E()
{
    printf("\nE -> T E'\t\t%s", cursor);
    return T() && Edash();
}

// T -> F T'
int T()
{
    printf("\nT -> F T'\t\t%s", cursor);
    return F() && Tdash();
}

// E' -> + T E' | $
int Edash()
{
    if (*cursor == '+')
    {
        printf("\nE' -> + T E'\t\t%s", cursor);
        cursor++;
        return T() && Edash();
    }
    else
    {
        printf("\nE' -> $\t\t%s", cursor);
        return SUCCESS;
    }
}

// T' -> * F T' | $
int Tdash()
{
    if (*cursor == '*')
    {
        printf("\nT' -> * F T'\t\t%s", cursor);
        cursor++;
        return F() && Tdash();
    }
    else
    {
        printf("\nT' -> $\t\t%s", cursor);
        return SUCCESS;
    }
}

// F -> ( E ) | i
int F()
{
    if (*cursor == '(')
    {
        printf("\nF -> ( E )\t\t%s", cursor);
        cursor++;
        if (E() && *cursor == ')')
        {
            cursor++;
            return SUCCESS;
        }
        else
        {
            return FAILED;
        }
    }
    else if (*cursor == 'i')
    {
        printf("\nF -> i\t\t%s", cursor);
        cursor++;
        return SUCCESS;
    }
    else
    {
        return FAILED;
    }
}
