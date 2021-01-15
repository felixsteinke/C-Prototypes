//Erstellt von Felix Steinke und Florian Grabowski

#include <stdio.h>
#include <string.h>

char *substring(char *string, int start) {
    char *a;
    a = string + start;
    return a;
}

int main(int argc, char *argv[]) {
    //result1 = result1 + args[i].substring(1);
    char result1[1024] = {0};
    int resultCounter1 = 0;

    for (int i = 1; i < argc; ++i) {
        char *a;
        for (a = substring(argv[i], 1); *a; a++) {
            result1[resultCounter1] = *a;
            resultCounter1++;
        }
        result1[resultCounter1] = '\0';
    }

    //result2 = result1.substring(result1.length()/2);
    char result2[512] = {0};
    int resultCounter2 = 0;

    char *b;
    for (b = substring(result1, resultCounter1 / 2); *b; b++) {
        result2[resultCounter2] = *b;
        resultCounter2++;
    }
    result2[resultCounter2] = '\0';

    //result1 = result1 + result2;
    strncat(result1, result2, 512);
    //System.out.println(result);
    printf("%s", result1);
    return 0;
}


