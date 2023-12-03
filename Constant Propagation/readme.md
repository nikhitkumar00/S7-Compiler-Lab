This C program demonstrates constant folding optimization on a series of expressions. The program takes user input for expressions, performs constant folding, and outputs the optimized code.

### Files

1. **main.c**: The main C code file containing the program logic.
2. **Functions.c**: Contains the functions for input, constant folding, and output.

### How to Use

1. **Compile**: Compile the program using a C compiler. For example, using GCC:
   ```bash
   gcc program.c
   ```

2. **Run**: Execute the compiled program:
   ```bash
   ./a.out
   ```

3. **Input**: Enter the maximum number of expressions and input expressions as prompted.

4. **Output**: The program will display the optimized code after constant folding.

### Example

```bash
Enter the maximum number of expressions: 3
Enter the input:
+ 2 3 T1
= T1 5
* T1 4 T2

Optimized code is:
= T1 5
* T1 4 T2
```

### Code Structure

- **main.c**: Contains the main program logic, including user input and function calls.
- **Functions.c**: Contains functions for input, constant folding, and output, organized for clarity.

### Notes

- The program assumes a maximum of 10 expressions for simplicity.
- Constant folding optimizations are applied to arithmetic expressions.
- Invalid input (e.g., non-numeric operands) may lead to unexpected results.

Feel free to explore, modify, and use the code as needed. If you have any questions or suggestions, please don't hesitate to reach out.