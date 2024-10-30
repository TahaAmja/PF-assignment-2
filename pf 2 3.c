#include <stdio.h>
#include <string.h>

// Function to compress a single word and return the count of removed characters
int compressWord(char *word, char *compressedWord) {
    int removedCount = 0;
    int j = 0; // Index for compressedWord

    for (int i = 0; i < strlen(word); i++) {
        if (i == 0 || word[i] != word[i - 1]) {
            compressedWord[j++] = word[i];
        } else {
            removedCount++;
        }
    }
    compressedWord[j] = '\0'; // Null-terminate the compressed word
    return removedCount;
}

// Function to apply compression to a list of words
void compressWords(char *words[], int wordCount, char compressedWords[][50], int *totalRemovedCount) {
    *totalRemovedCount = 0;
    
    for (int i = 0; i < wordCount; i++) {
        *totalRemovedCount += compressWord(words[i], compressedWords[i]);
    }
}

int main() {
    char *words[] = {"booooook", "coooool", "heeeey"};
    int wordCount = sizeof(words) / sizeof(words[0]);
    char compressedWords[3][50]; // Array to store compressed versions of words
    int totalRemovedCount;

    // Compress the words and get the total removed characters
    compressWords(words, wordCount, compressedWords, &totalRemovedCount);

    // Print the compressed words
    printf("Compressed words: ");
    for (int i = 0; i < wordCount; i++) {
        printf("%s ", compressedWords[i]);
    }

    // Print the total number of removed characters
    printf("\nTotal characters removed: %d\n", totalRemovedCount);

    return 0;
}
