#include <stdio.h>

void input_handling(int values[], int count) {
    // Print input values (for demonstration)
    printf("Input Values: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

void horizontal_histogram(int values[], int count) {
    // Generate and print horizontal histogram
    printf("Horizontal Histogram\n");
    for (int i = 0; i < count; i++) {
        printf("Value %d: ", i + 1);
        for (int j = 0; j < values[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void vertical_histogram(int values[], int count) {
    // Generate and print vertical histogram
    printf("\nVertical Histogram\n");
    int max_value = values[0];
    for (int i = 1; i < count; i++) {
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }

    for (int i = max_value; i > 0; i--) {
        for (int j = 0; j < count; j++) {
            if (values[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Print the base of the histogram
    for (int i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

int main() {
    int values[] = {3, 5, 1, 4};
    int count = sizeof(values) / sizeof(values[0]);

    // Handle input
    input_handling(values, count);

    // Print histograms
    horizontal_histogram(values, count);
    vertical_histogram(values, count);

    return 0;
}