#include <stdio.h>
#include <string.h>
#define MAX-CHAR 256

// Function to calculate and print character frequency for each slogan
void analyzeCharacterFrequency(char *slogans[], int n) {
    for (int i = 0; i < n; i++) {
        char *slogan = slogans[i];
        int freq[MAX_CHAR] = {0};

        // Count frequency of each character in the slogan
        for (int j = 0; slogan[j] != '\0'; j++) {
            freq[(int)slogan[j]]++;
        }

        // Print the result for the current slogan
        printf("For \"%s\": {", slogan);
        int first = 1;
        for (int k = 0; k < MAX_CHAR; k++) {
            if (freq[k] > 0) {
                if (!first) {
                    printf(", ");
                }
                printf("'%c': %d", k, freq[k]);
                first = 0;
            }
        }
        printf("}\n");
    }
}

int main() {
    char *slogans[] = {"buy now", "save big", "limited offer"};
    int n = sizeof(slogans) / sizeof(slogans[0]);

    analyzeCharacterFrequency(slogans, n);

    return 0;
}
