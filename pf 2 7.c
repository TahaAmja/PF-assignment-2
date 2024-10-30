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
    int score = 0