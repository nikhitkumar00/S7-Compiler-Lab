# First and Follow Set Calculation for Context-Free Grammar

This C program calculates the First and Follow sets for the given set of production rules in a context-free grammar. The grammar is specified through production rules in the form A->..., and the program computes the First and Follow sets for each non-terminal symbol.

## Key Components

### Production Structure
```c
struct Production {
    char nonTerminal;
    char production[MAX];
};
```
This structure represents a production rule with a non-terminal symbol and its corresponding production.

### Functions
- `findFirst`: Computes the First set for a given non-terminal symbol in a production rule.
- `findFollow`: Computes the Follow set for a given non-terminal symbol in a production rule.
- `isTerminal` and `isNonTerminal`: Check if a character is a terminal or non-terminal, respectively.
- `addToSet`: Adds a character to a set (First or Follow set).
- `printSet`: Prints the elements of a set.

### Main Function
```c
int main() {
    // ... (input production rules and initialize sets)

    // Calculate first and follow sets for each non-terminal
    for (i = 0; i < numProductions; i++) {
        findFirst(productions[i].nonTerminal, i, 3);
    }
    for (i = 0; i < numProductions; i++) {
        findFollow(productions[i].nonTerminal, i, 3);
    }

    // Print first sets
    // Print follow sets

    return 0;
}
```

### Input
- The user inputs the number of production rules and the production rules themselves.

### Output
- The program prints the calculated First and Follow sets for each non-terminal symbol.

## Example Usage
1. Compile the program: `gcc filename.c`
2. Run the compiled program: `./a.out`

3. Enter the number of production rules and each production rule in the form A->...
4. The program will display the calculated First and Follow sets for each non-terminal symbol.

Note: This program provides a basic implementation of First and Follow set calculations and assumes correct input. Enhancements can be made for error handling and to handle more complex grammars.