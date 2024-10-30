#include <stdio.h>

int matchsticks_to_pick(int N) {
    // Check if A can guarantee a win
    if (N <= 0) {
        return -1; // Invalid number of matchsticks
    }

    // Winning positions: If N % 5 == 0, A cannot guarantee a win
    if (N % 5 == 0) {
        return -1; // A cannot win
    }

    // A can win, return the number of matchsticks he should pick
    return N % 5;
}

int main() {
    int N;

    // Input the number of matchsticks
    printf("Enter the number of matchsticks: ");
    scanf("%d", &N);

    // Get the number of matchsticks A should pick
    int result = matchsticks_to_pick(N);

    // Output the result
    if (result == -1) {
        printf("A cannot guarantee a win.\n");
    } else {
        printf("A should pick %d matchsticks to guarantee a win.\n", result);
    }

    return 0;
}