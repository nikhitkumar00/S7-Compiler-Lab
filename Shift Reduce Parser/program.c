#include <stdio.h>
#include <string.h>

int main()
{
    /* initialize strings and pointers */
    char inputString[10] = {'a', 'b', 'c', 'b', 'a'};
    char stack[10];
    int stackPointer = 0, inputPointer = 0, inputLength = strlen(inputString);

    /* print initial grammar rules and input string */
    printf("\nThe Grammars are :\nE -> c\nR -> bEb\nS -> aRa\n\nThe Input String is abcba\n\n");

    /* print table headers */
    printf("STACK\t\tINPUT\t\tACTION\n\n");

    /* iterate through all characters of input string */
    for (int i = 0; i < inputLength; i++)
    {
        /* put the next input character onto the stack and update pointers */
        stack[stackPointer++] = inputString[inputPointer];
        stack[stackPointer] = '\0';
        inputString[inputPointer++] = ' ';

        /* print the current state and action */
        printf("%s\t\t%s\t\t%s\n", stack, inputString, "SHIFT");

        /* check if the top of the stack can be reduced according to the rule E -> c */
        if (stack[stackPointer - 1] == 'c')
        {
            stack[stackPointer - 1] = 'E';
            printf("%s\t\t%s\t\t%s\n", stack, inputString, "REDUCE E -> c");
        }

        /* check if the top three elements of the stack can be reduced according to the rule R -> bEb */
        if (stack[stackPointer - 1] == 'b' && stack[stackPointer - 2] == 'E' && stack[stackPointer - 3] == 'b')
        {
            stack[stackPointer - 3] = 'R';
            stack[stackPointer - 2] = '\0';
            stack[stackPointer - 1] = '\0';
            stackPointer = stackPointer - 2;

            printf("%s\t\t%s\t\t%s\n", stack, inputString, "REDUCE R -> bEb");
        }

        /* check if the top three elements of the stack can be reduced according to the rule S -> aRa */
        if (stack[stackPointer - 1] == 'a' && stack[stackPointer - 2] == 'R' && stack[stackPointer - 3] == 'a')
        {
            stack[stackPointer - 3] = 'S';
            stack[stackPointer - 2] = '\0';
            stack[stackPointer - 1] = '\0';
            stackPointer = stackPointer - 2;

            printf("%s\t\t%s\t\t%s\n", stack, inputString, "REDUCE S -> aRa");
        }
    }

    /* if the stack only contains S, then the input string is valid according to the grammar rules */
    if (stack[0] == 'S' && stack[1] == '\0')
    {
        printf("\nSTRING IS ACCEPTED\n\n");
    }
    /* else the input string is invalid */
    else
    {
        printf("\nSTRING IS REJECTED\n\n");
    }
}