#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void input();
void output();
void change(int p, char *res);
void constant();

// Structure to represent an expression
struct expr
{
    char op[2], op1[5], op2[5], res[5];
    int flag;
} arr[10];

int n;

int main()
{
    // Function calls to perform constant folding and output optimized code
    input();
    constant();
    output();

    return 0;
}

// Function to take input expressions from the user
void input()
{
    int i;
    printf("Enter the maximum number of expressions: ");
    scanf("%d", &n);

    if (n <= 0 || n > 10)
    {
        printf("Invalid number of expressions. Exiting program.\n");
        exit(1);
    }

    printf("Enter the input:\n");

    // Loop to input expressions
    for (i = 0; i < n;)
    {
        scanf("%s", arr[i].op);
        scanf("%s", arr[i].op1);
        scanf("%s", arr[i].op2);
        scanf("%s", arr[i].res);
        arr[i].flag = 0; // Initialize flag to 0

        i++; // Increment i only when a valid expression is entered
    }
}

// Function to perform constant folding optimization
void constant()
{
    int i;
    int op1, op2, res;
    char op, res1[5];

    // Loop through expressions
    for (i = 0; i < n; i++)
    {
        // Check if operands are constants or if the operation is an assignment
        if (isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0]) || strcmp(arr[i].op, "=") == 0)
        {
            op1 = atoi(arr[i].op1);
            op2 = atoi(arr[i].op2);
            op = arr[i].op[0];

            // Perform the operation based on the operator
            switch (op)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '=':
                res = op1;
                break;
            }

            // Convert the result to string and set the flag
            sprintf(res1, "%d", res);
            arr[i].flag = 1;

            // Update expressions that use the result
            change(i, res1);
        }
    }
}

// Function to output the optimized code
void output()
{
    int i;

    printf("\nOptimized code is:\n");

    // Loop to print optimized code
    for (i = 0; i < n; i++)
    {
        if (!arr[i].flag)
            printf("%s %s %s %s\n", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
    }
}

// Function to update expressions that use the result of a constant-folding operation
void change(int p, char *res)
{
    int i;

    // Loop to update dependent expressions
    for (i = p + 1; i < n; i++)
    {
        if (strcmp(arr[p].res, arr[i].op1) == 0)
            strcpy(arr[i].op1, res);
        else if (strcmp(arr[p].res, arr[i].op2) == 0)
            strcpy(arr[i].op2, res);
    }
}
