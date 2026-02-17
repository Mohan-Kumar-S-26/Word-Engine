#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word_freq.h"  // Include our custom header

#define FILENAME "text.txt"

// We need to access these from word_freq.c
extern Word words[MAX_WORDS];
extern int uniqueWordCount;

int main() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error: Could not open %s.\n", FILENAME);
        return 1;
    }

    char buffer[MAX_LENGTH];
    printf("Reading file...\n");

    while (fscanf(file, "%s", buffer) != EOF) {
        cleanWord(buffer);
        if (strlen(buffer) > 1 && !isStopWord(buffer)) {
            addWord(buffer);
        }
    }
    fclose(file);
    
    sortWords();

    printf("\nTOP WORDS:\n");
    for (int i = 0; i < uniqueWordCount && i < 10; i++) {
        printf("%-12s : ", words[i].word);
        printHistogram(words[i].count);
        printf("\n");
    }

    // Interactive Search
    char search[MAX_LENGTH];
    while (1) {
        printf("\nSearch word (or 'exit'): ");
        scanf("%s", search);
        if (strcmp(search, "exit") == 0) break;

        cleanWord(search);
        int found = 0;
        for (int i = 0; i < uniqueWordCount; i++) {
            if (strcmp(words[i].word, search) == 0) {
                printf(">> '%s' found %d times.\n", search, words[i].count);
                found = 1; break;
            }
        }
        if (!found) printf(">> Not found.\n");
    }
    return 0;
}