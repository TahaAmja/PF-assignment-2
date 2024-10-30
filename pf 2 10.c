#include <stdio.h>


 void printStarPattern(int N) {
    int i, j;

    // Loop through each row
    for (i = 0; i < N; i++) {
        // Loop through each column
        for (j = 0; j < N; j++) {
            // Determine the conditions for printing stars
            if (j == N / 2 || (i + j == N / 2) || (i - j == N / 2) || 
                (j - i == N / 2) || (i + j == (3 * N) / 2 - 1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n"); // Move to the next line after finishing a row
    }
}

int main() {
    int N;

    // Prompt the user to enter an odd value for N
    printf("Enter an odd value for N: ");
    scanf("%d", &N);

    // Validate that N is odd
    if (N % 2 == 0) {
        printf("Please enter an odd value.\n");
        return 1; // Exit if the input is invalid
    }

    // Call the function to print the star pattern
    printStarPattern(N);

    return 0; // Indicate that the program ended successfully
}