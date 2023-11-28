#include <stdio.h>
#include <string.h>

#define MAX_STATES 20
#define STATE_LENGTH 3

char states[MAX_STATES][STATE_LENGTH];
char result[MAX_STATES][STATE_LENGTH];

void addState(char state[STATE_LENGTH], int *count) {
    strcpy(result[(*count)++], state);
}

void displayClosure(char copy[STATE_LENGTH], int count) {
    printf("\n Epsilon closure of %s = { ", copy);
    for (int i = 0; i < count; i++) {
        printf(" %s", result[i]);
    }
    printf(" } \n");
}

int main() {
    FILE *inputFile;
    inputFile = fopen("input.dat", "r");

    int numStates;
    printf("Enter the number of states: ");
    scanf("%d", &numStates);

    printf("Enter the states: ");
    for (int i = 0; i < numStates; i++) {
        scanf("%s", states[i]);
    }

    for (int i = 0; i < numStates; i++) {
        int count = 0;
        char currentState[STATE_LENGTH];
        strcpy(currentState, states[i]);
        addState(currentState, &count);

        while (1) {
            char nextState1[STATE_LENGTH], input[3], nextState2[STATE_LENGTH];
            int end = fscanf(inputFile, "%s%s%s", nextState1, input, nextState2);

            if (end == EOF) {
                break;
            }

            if (strcmp(currentState, nextState1) == 0 && strcmp(input, "e") == 0) {
                addState(nextState2, &count);
                strcpy(currentState, nextState2);
            }
        }

        displayClosure(states[i], count);
        rewind(inputFile);
    }

    fclose(inputFile);

    return 0;
}
