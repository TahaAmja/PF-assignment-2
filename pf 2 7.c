#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 6
#define COLS 5

// Function to print the 2D array
void print_array(char arr[ROWS][COLS]) {
    printf("\nCharacter Array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to search for a string in the 2D array
int search_string(char arr[ROWS][COLS], const char *str) {
    int length = strlen(str);
    // Search left to right and top to bottom
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Check right
            if (j <= COLS - length) {
                int found = 1;
                for (int k = 0; k < length; k++) {
                    if (arr[i][j + k] != str[k]) {
                        found = 0;
                        break;
                    }
                }
                if (found) {
                    return 1; // Found
                }
            }

            // Check down
            if (i <= ROWS - length) {
                int found = 1;
                for (int k = 0; k < length; k++) {
                    if (arr[i + k][j] != str[k]) {
                        found = 0;
                        break;
                    }
                }
                if (found) {
                    return 1; // Found
                }
            }
        }
    }
    return 0; // Not found
}

int main() {
    char arr[ROWS][COLS];
    int score = 0;
    char input[100];

    // Seed the random number generator
    srand(time(NULL));

    // Populate the array with random characters
    for (int i = 0; i < ROWS - 1; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = 'A' + rand() % 26; // Random letter A-Z
        }
    }

    // Set the last row with student ID's last four digits (example: 1234)
    arr[ROWS - 1][0] = '1';
    arr[ROWS - 1][1] = '2';
    arr[ROWS - 1][2] = '3';
    arr[ROWS - 1][3] = '4';
    arr[ROWS - 1][4] = 'Q'; // Optional character

    while (1) {
        print_array(arr);
printf("Enter a string to search (or type 'END' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "END") == 0) {
            break;
        }

        if (search_string(arr, input)) {
            score++;
            printf("%s is present Score %d\n", input, score);
        } else {
            score--;
            printf("%s is not present Score %d\n", input, score);
        }
    }

    return 0;
}
