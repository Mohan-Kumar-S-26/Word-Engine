#ifndef WORD_FREQ_H
#define WORD_FREQ_H

#define MAX_WORDS 2000
#define MAX_LENGTH 50

typedef struct {
    char word[MAX_LENGTH];
    int count;
} Word;

// Function Declarations
void cleanWord(char *str);
int isStopWord(char *str);
void addWord(char *str);
void sortWords();
void printHistogram(int count);

#endif