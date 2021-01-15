#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

static int globalChars = 0;
static int globalWords = 0;
static int globalLines = 0;

void countWords(const char *);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Syntax: %s <file name>\n", argv[0]);
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        countWords(argv[i]);
    }
    if (argc > 2) {
        printf("%5d %5d %5d %s\n", globalLines, globalWords, globalChars, "insgesamt");
    }
}

void countWords(const char *name) {
    FILE *input = fopen(name, "r");
    if (input == NULL) {
        perror(name);
        return;
    }
    int next = 0;
    int last;
    int chars = 0, words = 0, lines = 0;
    while ((next = getc(input)) != EOF) {
        chars++;
        if (!isspace(next) && isspace(last)) {
            words++;
        }
        if (next == '\n') {
            lines++;
        }
        last = next;
    }
    printf("%5d %5d %5d %s\n", lines, words, chars, name);
    fclose(input);
    globalChars += chars;
    globalWords += words;
    globalLines += lines;

}
