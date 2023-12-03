#include <stdio.h>
#include <string.h>

#define SUCCESS 1
#define FAILED 0

const char *cursor;
char string[64];

// Function prototypes
int E(), Edash(), T(), Tdash(), F();

int main()
{
    puts("Enter the string");
    scanf("%s", string);
    cursor = string;
    puts("\nInput         Action");
    puts("-----------------------");

    if (E() && *cursor == '\0')
    {
        puts("-----------------------");
        puts("String is successfully parsed");
        return 0;
    }
    else
    {
        puts("-----------------------");
        puts("Error in parsing String");
        return 1;
    }
}

// Grammar rule: E -> T E'
int E()
{
    printf("%-12s E -> T E'\n", cursor);
    return T() && Edash();
}

// Grammar rule: E' -> + T E' | $
int Edash()
{
    if (*cursor == '+')
    {
        printf("%-12s E' -> + T E'\n", cursor++);
        return T() && Edash();
    }
    else
    {
        printf("%-12s E' -> $\n", cursor);
        return SUCCESS;
    }
}

// Grammar rule: T -> F T'
int T()
{
    printf("%-12s T -> F T'\n", cursor);
    return F() && Tdash();
}

// Grammar rule: T' -> * F T' | $
int Tdash()
{
    if (*cursor == '*')
    {
        printf("%-12s T' -> * F T'\n", cursor++);
        return F() && Tdash();
    }
    else
    {
        printf("%-12s T' -> $\n", cursor);
        return SUCCESS;
    }
}

// Grammar rule: F -> ( E ) | i
int F()
{
    if (*cursor == '(')
    {
        printf("%-12s F -> ( E )\n", cursor++);
        return E() && (*cursor == ')' ? cursor++ && SUCCESS : FAILED);
    }
    else if (*cursor == 'i')
    {
        printf("%-12s F -> i\n", cursor++);
        return SUCCESS;
    }
    else
    {
        return FAILED;
    }
}
