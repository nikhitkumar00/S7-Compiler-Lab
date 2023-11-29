# Recursive Descent Parser for Arithmetic Expressions

This C program implements a recursive descent parser for parsing arithmetic expressions based on the given grammar rules:

```
E -> T E'
E' -> + T E' | $
T -> F T'
T' -> * F T' | $
F -> ( E ) | i
```

## Key Components

- `E`, `Edash`, `T`, `Tdash`, `F`: These functions correspond to the non-terminals in the grammar rules. The recursive structure of these functions reflects the grammar.

- `main`: Accepts input string, initializes the cursor, and invokes the `E` function. If the parsing is successful and the cursor reaches the end of the string, it indicates that the string is successfully parsed.

## Execution

1. The program prompts the user to enter an input string.

2. The input string is parsed using the recursive descent parser.

3. The parsing process is displayed step by step, showing the current input and the corresponding action taken.

4. The program prints whether the string is successfully parsed or if there is an error in parsing.

## Example Usage

1. Compile the program: `gcc filename.c`

2. Run the compiled program: `./a.out`

3. Enter an arithmetic expression (e.g., `i + (i * i)`).

4. The program will display the parsing steps and indicate whether the string is successfully parsed or if there is an error.

## Note

This is a basic implementation of a recursive descent parser for a simple arithmetic expression grammar. It assumes correct input and provides a minimal example for educational purposes. In a more complete implementation, error handling and recovery mechanisms would be added for robustness.