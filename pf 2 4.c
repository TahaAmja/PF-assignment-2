#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_LENGTH 50

// Helper function to sort characters in a string
void sortString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// Function to check if two strings are anagrams
int areAnagrams(char *str1, char *str2) {
    char sortedStr1[MAX_LENGTH], sortedStr2[MAX_LENGTH];
    strcpy(sortedStr1, str1);
    strcpy(sortedStr2, str2);

    // Sort both strings
    sortString(sortedStr1);
    sortString(sortedStr2);

    // Compare sorted strings
    return strcmp(sortedStr1, sortedStr2) == 0;
}

// Function to group scrambled transactions
void groupScrambledTransactions(char transactions[][MAX_LENGTH], int n) {
    int grouped[MAX_TRANSACTIONS] = {0}; // Array to mark grouped transactions

    for (int i = 0; i < n; i++) {
        if (grouped[i]) continue; // Skip if already grouped

        printf("[");
        printf("\"%s\"", transactions[i]);
        grouped[i] = 1;

        for (int j = i + 1; j < n; j++) {
            if (!grouped[j] && areAnagrams(transactions[i], transactions[j])) {
                printf(", \"%s\"", transactions[j]);
                grouped[j] = 1;
            }
        }
        printf("]\n");
    }
}

int main() {
    char transactions[][MAX_LENGTH] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int n = sizeof(transactions) / sizeof(transactions[0]);

    printf("Grouped scrambled transactions:\n");
    groupScrambledTransactions(transactions, n);

    return 0;
}