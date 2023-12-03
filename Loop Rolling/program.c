#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int roll(unsigned int n);
int unroll(unsigned int n);

int main()
{
    unsigned int n;
    int x, ch;

    // Input for N
    printf("Enter N: ");
    scanf("%u", &n);

    // Menu for options
    printf("\n1. Loop Roll\n2. Loop UnRoll\n3. Exit\n");

    // Menu loop
    while (1)
    {
        // User choice input
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            x = roll(n);
            printf("Count of 1's: %d\n", x);
            break;
        case 2:
            x = unroll(n);
            printf("Count of 1's: %d\n", x);
            break;
        case 3:
            exit(0);
        default:
            printf("\nWrong Choice\n");
        }
    }

    return 0;
}

// Function to count set bits using loop roll
int roll(unsigned int n)
{
    int bits = 0, i = 0;

    // Loop to iterate through bits
    while (n != 0)
    {
        if (n & 1)
            bits++;

        n >>= 1;
        i++;
    }

    // Output and comments
    printf("\nLoop Roll:\n");
    printf("No. of iterations: %d\n", i);
    return bits;
}

// Function to count set bits using loop unroll
int unroll(unsigned int n)
{
    int bits = 0, i = 0;

    // Loop to iterate through bits with unrolling
    while (n != 0)
    {
        if (n & 1)
            bits++;
        if (n & 2)
            bits++;
        if (n & 4)
            bits++;
        if (n & 8)
            bits++;

        n >>= 4;
        i++;
    }

    // Output and comments
    printf("\nLoop UnRoll:\n");
    printf("No. of iterations: %d\n", i);
    return bits;
}
