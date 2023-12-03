// Including Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global Variables
int z = 0, i = 0, j = 0, c = 0;

// Modify array size to increase
// length of string to be parsed
char a[16], ac[20], stk[15], act[10];

// This Function will check whether
// the stack contains a production rule
// that needs to be reduced.
// Production rules can be E->4, E->2E2, or E->3E3.
void check()
{
    // Copying the string to be printed as an action
    strcpy(ac, "REDUCE TO E -> ");

    // Loop through the length of the input string
    for (z = 0; z < c; z++)
    {
        // Check for the production rule E->4
        if (stk[z] == '4')
        {
            printf("%s4", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';

            // Print the action
            printf("\n$%s\t%s$\t", stk, a);
        }
    }

    // Loop through the stack to check for other production rules
    for (z = 0; z < c - 2; z++)
    {
        // Check for the production rule E->2E2
        if (stk[z] == '2' && stk[z + 1] == 'E' &&
            stk[z + 2] == '2')
        {
            printf("%s2E2", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            i = i - 2; // Update index after reduction
        }

        // Check for the production rule E->3E3
        if (stk[z] == '3' && stk[z + 1] == 'E' &&
            stk[z + 2] == '3')
        {
            printf("%s3E3", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            i = i - 2; // Update index after reduction
        }
    }
    return; // Return to the main function
}

// Driver Function
int main()
{
    printf("GRAMMAR is -\nE->2E2 \nE->3E3 \nE->4\n");

    // Input string
    strcpy(a, "32423");

    // Calculate the length of the input string
    c = strlen(a);

    // "SHIFT" is copied to 'act' to be printed
    strcpy(act, "SHIFT");

    // Print Labels (column names)
    printf("\nstack \t input \t action");

    // Print the initial values of the stack and input
    printf("\n$\t%s$\t", a);

    // Loop through the input string
    for (i = 0; j < c; i++, j++)
    {
        // Print the action
        printf("%s", act);

        // Push into the stack
        stk[i] = a[j];
        stk[i + 1] = '\0';

        // Move the pointer
        a[j] = ' ';

        // Print the action
        printf("\n$%s\t%s$\t", stk, a);

        // Call the check function, which will
        // check the stack for any production
        check();
    }

    // Rechecking one last time for any valid production
    check();

    // If the top of the stack is E (starting symbol),
    // then accept the input
    if (stk[0] == 'E' && stk[1] == '\0')
        printf("Accept\n");
    else // Otherwise, reject
        printf("Reject\n");
}
