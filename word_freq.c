#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "word_freq.h"

// Global variables definition
Word words[MAX_WORDS];
int uniqueWordCount = 0;

// Internal stop words list
char *stopWords[] = {
    "is", "a", "the", "and", "of", "to", "in", "on", "at", 
    "for", "with", "it", "that", "this", "are", "was", "be", "i"
};
int stopWordsLen = 18;

int isStopWord(char *str) {
    for (int i = 0; i < stopWordsLen; i++) {
        if (strcmp(str, stopWords[i]) == 0) return 1;
    }
    return 0;
}

void cleanWord(char *str) {
    int j = 0;
    char temp[MAX_LENGTH];
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) temp[j++] = tolower(str[i]);
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

void addWord(char *str) {
    if (uniqueWordCount >= MAX_WORDS) return;

    for (int i = 0; i < uniqueWordCount; i++) {
        if (strcmp(words[i].word, str) == 0) {
            words[i].count++;
            return;
        }
    }
    strcpy(words[uniqueWordCount].word, str);
    words[uniqueWordCount].count = 1;
    uniqueWordCount++;
}

void sortWords() {
    for (int i = 0; i < uniqueWordCount - 1; i++) {
        for (int j = 0; j < uniqueWordCount - i - 1; j++) {
            if (words[j].count < words[j + 1].count) {
                Word temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

void printHistogram(int count) {
    printf("[");
    for (int i = 0; i < count; i++) printf("#");
    printf("] %d", count);
}