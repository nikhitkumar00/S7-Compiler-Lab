#include <stdio.h>
#include <string.h>

#define MAX 10

struct Production
{
    char nonTerminal;
    char production[MAX];
};

struct Production productions[MAX];
int numProductions;

char firstSets[MAX][MAX] = {0};
char followSets[MAX][MAX] = {0};

int isTerminal(char symbol)
{
    return !(symbol >= 'A' && symbol <= 'Z');
}

void addToSet(char symbol, char set[])
{
    for (int i = 0; i < MAX && set[i] != '\0'; i++)
    {
        if (set[i] == symbol)
        {
            return;
        }
    }
    set[strlen(set)] = symbol;
}

void printSet(char set[])
{
    for (int i = 0; i < MAX && set[i] != '\0'; i++)
    {
        printf("%c ", set[i]);
    }
}

void findFirst(char nonTerminal, int ruleIndex)
{
    for (int j = 3; productions[ruleIndex].production[j] != '\0'; j++)
    {
        char currentSymbol = productions[ruleIndex].production[j];

        if (isTerminal(currentSymbol))
        {
            addToSet(currentSymbol, firstSets[ruleIndex]);
            break;
        }
        else
        {
            int nextRuleIndex = -1;
            for (int k = 0; k < numProductions; k++)
            {
                if (productions[k].nonTerminal == currentSymbol)
                {
                    nextRuleIndex = k;
                    break;
                }
            }

            if (nextRuleIndex != -1)
            {
                findFirst(currentSymbol, nextRuleIndex);
                for (int k = 0; firstSets[nextRuleIndex][k] != '\0'; k++)
                {
                    if (firstSets[nextRuleIndex][k] != '#')
                    {
                        addToSet(firstSets[nextRuleIndex][k], firstSets[ruleIndex]);
                    }
                }

                if (firstSets[nextRuleIndex][0] != '#')
                {
                    break;
                }
            }
        }
    }
}

void findFollow(char nonTerminal, int ruleIndex)
{
    for (int i = 0; i < numProductions; i++)
    {
        for (int j = 3; productions[i].production[j] != '\0'; j++)
        {
            if (productions[i].production[j] == nonTerminal)
            {
                int nextSymbolIndex = j + 1;

                while (productions[i].production[nextSymbolIndex] != '\0')
                {
                    if (isTerminal(productions[i].production[nextSymbolIndex]))
                    {
                        addToSet(productions[i].production[nextSymbolIndex], followSets[ruleIndex]);
                        break;
                    }
                    else
                    {
                        int nextNonTerminalIndex = -1;
                        for (int k = 0; k < numProductions; k++)
                        {
                            if (productions[k].nonTerminal == productions[i].production[nextSymbolIndex])
                            {
                                nextNonTerminalIndex = k;
                                break;
                            }
                        }

                        if (nextNonTerminalIndex != -1)
                        {
                            for (int k = 0; firstSets[nextNonTerminalIndex][k] != '\0'; k++)
                            {
                                if (firstSets[nextNonTerminalIndex][k] != '#')
                                {
                                    addToSet(firstSets[nextNonTerminalIndex][k], followSets[ruleIndex]);
                                }
                            }

                            if (firstSets[nextNonTerminalIndex][0] != '#')
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }

                    nextSymbolIndex++;
                }

                if (productions[i].production[nextSymbolIndex] == '\0')
                {
                    if (i != ruleIndex)
                    {
                        findFollow(productions[i].nonTerminal, i);
                        for (int k = 0; followSets[i][k] != '\0'; k++)
                        {
                            addToSet(followSets[i][k], followSets[ruleIndex]);
                        }
                    }
                }
            }
        }
    }
}

void calculateSets()
{
    for (int i = 0; i < numProductions; i++)
    {
        findFirst(productions[i].nonTerminal, i);
    }
    for (int i = 0; i < numProductions; i++)
    {
        findFollow(productions[i].nonTerminal, i);
    }
    addToSet('$', followSets[0]);
}

int main()
{
    printf("Enter the number of production rules: ");
    scanf("%d", &numProductions);

    printf("Enter the production rules:\n");
    for (int i = 0; i < numProductions; i++)
    {
        printf("Enter production %d (in the form A->...): ", i + 1);
        scanf("%s", productions[i].production);
        productions[i].nonTerminal = productions[i].production[0];
    }

    calculateSets();

    printf("\nFirst Sets:\n");
    for (int i = 0; i < numProductions; i++)
    {
        printf("First(%c) = ", productions[i].nonTerminal);
        printSet(firstSets[i]);
        printf("\n");
    }

    printf("\nFollow Sets:\n");
    for (int i = 0; i < numProductions; i++)
    {
        printf("Follow(%c) = ", productions[i].nonTerminal);
        printSet(followSets[i]);
        printf("\n");
    }

    return 0;
}
