#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct expr
{
    char operator[5];
    char operand1[5];
    char operand2[5];
    char result[5];
    int optimized;
} expression[10];

void main()
{
    int numberOfExpressions;
    char strresult[10];

    printf("\nEnter the number of expressions: ");
    scanf("%d", &numberOfExpressions);

    for (int i = 0; i < numberOfExpressions; i++)
    {
        scanf("%s\t%s\t%s\t%s", expression[i].operator, expression[i].operand1, expression[i].operand2, expression[i].result);
        expression[i].optimized = 0;
    }

    for (int i = 0; i < numberOfExpressions; i++)
    {
        if (isdigit(expression[i].operand1[0]) && isdigit(expression[i].operand2[0]) || expression[i].operator[0] == '=')
        {
            int op1, op2, result;
            op1 = atoi(expression[i].operand1);
            op2 = atoi(expression[i].operand2);
            switch (expression[i].operator[0])
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            case '=':
                result = op1;
                break;
            }
            expression[i].optimized = 1;
            sprintf(strresult, "%d", result);

            for (int j = i + 1; j < numberOfExpressions; j++)
            {
                if (strcmp(expression[j].operand1, expression[i].result) == 0)
                {
                    strcpy(expression[j].operand1, strresult);
                }
                if (strcmp(expression[j].operand2, expression[i].result) == 0)
                {
                    strcpy(expression[j].operand2, strresult);
                }
            }
        }
    }
    for (int i = 0; i < numberOfExpressions; i++)
    {
        printf("\n%s\t%s\t%s\t%s", expression[i].operator, expression[i].operand1, expression[i].operand2, expression[i].result);
    }
}
