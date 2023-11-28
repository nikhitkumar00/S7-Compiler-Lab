#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// Structure to represent a production rule
struct Production {
    char nonTerminal;
    char production[MAX];
};

// Function to find the first set of a given non-terminal
void findFirst(char, int, int);

// Function to find the follow set of a given non-terminal
void findFollow(char, int, int);

// Function to check if a character is a terminal
int isTerminal(char);

// Function to check if a character is a non-terminal
int isNonTerminal(char);

// Function to add a character to a set
void addToSet(char, char[], int*);

// Function to print a set
void printSet(char[]);

// Production rules
struct Production productions[MAX];
int numProductions;

// First and Follow sets
char firstSets[MAX][MAX];
char followSets[MAX][MAX];

int main() {
    int i, j;
    
    // Input the number of production rules
    printf("Enter the number of production rules: ");
    scanf("%d", &numProductions);

    // Input production rules
    printf("Enter the production rules:\n");
    for (i = 0; i < numProductions; i++) {
        printf("Enter production %d (in the form A->...): ", i + 1);
        scanf("%s", productions[i].production);
        productions[i].nonTerminal = productions[i].production[0];
    }

    // Initialize first and follow sets
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            firstSets[i][j] = '\0';
            followSets[i][j] = '\0';
        }
    }

    // Calculate first and follow sets for each non-terminal
    for (i = 0; i < numProductions; i++) {
        findFirst(productions[i].nonTerminal, i, 3);
    }
    for (i = 0; i < numProductions; i++) {
        findFollow(productions[i].nonTerminal, i, 3);
    }

    // Print first sets
    printf("\nFirst Sets:\n");
    for (i = 0; i < numProductions; i++) {
        printf("First(%c) = ", productions[i].nonTerminal);
        printSet(firstSets[i]);
        printf("\n");
    }

    // Print follow sets
    printf("\nFollow Sets:\n");
    for (i = 0; i < numProductions; i++) {
        printf("Follow(%c) = ", productions[i].nonTerminal);
        printSet(followSets[i]);
        printf("\n");
    }

    return 0;
}

// Function to find the first set of a given non-terminal
void findFirst(char nonTerminal, int ruleIndex, int pos) {
    int i, j, k, foundEpsilon;

    // If the first character is a terminal, add it to the first set
    if (isTerminal(productions[ruleIndex].production[pos])) {
        addToSet(productions[ruleIndex].production[pos], firstSets[ruleIndex], &pos);
        return;
    }

    // If the first character is a non-terminal, find its first set
    for (i = 0; i < numProductions; i++) {
        if (productions[i].nonTerminal == productions[ruleIndex].production[pos]) {
            foundEpsilon = 0;

            // Find the first set of the non-terminal in the production
            for (j = 3; j < strlen(productions[i].production); j++) {
                findFirst(productions[i].production[j], i, j);

                // Add the first set (excluding epsilon) to the current first set
                for (k = 0; k < MAX; k++) {
                    if (firstSets[i][k] != '\0' && firstSets[i][k] != '#') {
                        addToSet(firstSets[i][k], firstSets[ruleIndex], &pos);
                    }
                }

                // If epsilon is in the first set, continue to the next character
                if (firstSets[i][0] == '#' && productions[i].production[j + 1] == '\0') {
                    foundEpsilon = 1;
                } else {
                    break;
                }
            }

            // If epsilon is in the first set of all characters, add epsilon to the first set
            if (foundEpsilon) {
                addToSet('#', firstSets[ruleIndex], &pos);
            }
        }
    }
}

// Function to find the follow set of a given non-terminal
void findFollow(char nonTerminal, int ruleIndex, int pos) {
    int i, j, k, foundEpsilon;

    // If the non-terminal is the start symbol, add $ to its follow set
    if (ruleIndex == 0 && pos == 3) {
        addToSet('$', followSets[ruleIndex], &pos);
    }

    // Find the production rule containing the non-terminal
    for (i = 0; i < numProductions; i++) {
        for (j = 3; j < strlen(productions[i].production); j++) {
            if (productions[i].production[j] == nonTerminal) {
                foundEpsilon = 0;

                // Add the first set of the next character to the follow set
                for (k = j + 1; k < strlen(productions[i].production); k++) {
                    if (isTerminal(productions[i].production[k])) {
                        addToSet(productions[i].production[k], followSets[ruleIndex], &pos);
                        break;
                    } else {
                        for (int l = 0; l < MAX; l++) {
                            if (firstSets[ruleIndex][l] != '\0' && firstSets[ruleIndex][l] != '#') {
                                addToSet(firstSets[ruleIndex][l], followSets[ruleIndex], &pos);
                            }
                        }

                        // If epsilon is in the first set, continue to the next character
                        if (firstSets[ruleIndex][0] == '#' && productions[i].production[k] == '\0') {
                            foundEpsilon = 1;
                        } else {
                            break;
                        }
                    }
                }

                // If epsilon is in the first set of all characters, add follow(A) to follow(B)
                if (foundEpsilon) {
                    findFollow(productions[i].nonTerminal, i, j);
                }
            }
        }
    }
}

// Function to check if a character is a terminal
int isTerminal(char symbol) {
    return !(symbol >= 'A' && symbol <= 'Z');
}

// Function to check if a character is a non-terminal
int isNonTerminal(char symbol) {
    return (symbol >= 'A' && symbol <= 'Z');
}

// Function to add a character to a set
void addToSet(char symbol, char set[], int *pos) {
    int i;

    // Check if the character is already in the set
    for (i = 0; i < MAX; i++) {
        if (set[i] == symbol) {
            return;
        }
    }

    // Add the character to the set
    set[*pos] = symbol;
    (*pos)++;
}

// Function to print a set
void printSet(char set[]) {
    int i;

    // Print the set
    for (i = 0; i < MAX; i++) {
        if (set[i] != '\0') {
            printf("%c ", set[i]);
        }
    }
}
