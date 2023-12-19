#include <stdio.h>
#include <string.h>

int main()
{
    char inputString[10] = {'a', 'b', 'c', 'b', 'a'};
    char stack[10];
    int stackPointer = 0, inputPointer = 0, inputLength = strlen(inputString);

    printf("\nThe Grammars are :\nE -> c\nR -> bEb\nS -> aRa\n\nThe Input String is abcba\n\n");

    printf("STACK\t\tINPUT\t\tACTION\n\n");
    for (int i = 0; i < inputLength; i++)
    {
        stack[stackPointer] = inputString[inputPointer];
        stackPointer++;
        stack[stackPointer] = '\0';
        inputString[inputPointer] = ' ';
        inputPointer++;

        printf("%s\t\t%s\t\t%s\n", stack, inputString, "SHIFT");

        if (stack[stackPointer - 1] == 'c')
        {
            stack[stackPointer - 1] = 'E';
            printf("%s\t\t%s\t\t%s\n", stack, inputString, "REDUCE E -> c");
        }

        if (stack[stackPointer - 1] == 'b' && stack[stackPointer - 2] == 'E' && stack[stackPointer - 3] == 'b')
        {
            stack[stackPointer - 3] = 'R';
            stack[stackPointer - 2] = '\0';
            stack[stackPointer - 1] = '\0';
            stackPointer = stackPointer - 2;

            printf("%s\t\t%s\t\t%s\n", stack, inputString, "REDUCE R -> bEb");
        }

        if (stack[stackPointer - 1] == 'a' && stack[stackPointer - 2] == 'R' && stack[stackPointer - 3] == 'a')
        {
            stack[stackPointer - 3] = 'S';
            stack[stackPointer - 2] = '\0';
            stack[stackPointer - 1] = '\0';
            stackPointer = stackPointer - 2;

            printf("%s\t\t%s\t\t%s\n", stack, inputString, "REDUCE S -> aRa");
        }
    }
    if (stack[0] == 'S' && stack[1] == '\0')
    {
        printf("\nSTRING IS ACCEPTED\n\n");
    }
    else
    {
        printf("\nSTRING IS REJECTED\n\n");
    }
}