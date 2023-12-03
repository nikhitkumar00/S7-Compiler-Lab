### Readme - Counting Set Bits in C

This repository contains C code for counting the number of set bits (1s) in a given unsigned integer using two different approaches: Loop Roll and Loop Unroll. The user is prompted to enter a value (`N`), and they can choose between the two methods or exit the program.

### Files

1. **main.c**: The main C code file containing the menu-driven program.
2. **Functions.c**: Contains the functions `roll` and `unroll` for counting set bits using loop roll and loop unroll, respectively.

### How to Use

1. **Compile**: Compile the program using a C compiler. For example, using GCC:
   ```bash
   gcc program.c
   ```

2. **Run**: Execute the compiled program:
   ```bash
   ./a.out
   ```

3. **Input**: Enter a value for `N` as prompted.

4. **Menu Options**:
   - 1: Loop Roll - Count set bits using a loop.
   - 2: Loop Unroll - Count set bits using loop unrolling.
   - 3: Exit - Terminate the program.

### Example

```bash
Enter N: 255

1. Loop Roll
2. Loop UnRoll
3. Exit

Enter your choice: 1
Count of 1's: 8

Enter your choice: 2
Count of 1's: 8

Enter your choice: 3
```

### Code Improvement

The code has been formatted for readability and commented to explain each section. Meaningful variable names and consistent indentation have been used for better understanding.

### Notes

- This program assumes an unsigned integer input.
- Loop unrolling is implemented for illustration purposes; in practice, it may not always lead to performance improvements.