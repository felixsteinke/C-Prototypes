//
// Created by stein on 03.04.2020.
//
#include <stdio.h>
#include <string.h>

float bmi(int weight, int size){
    return (float) weight * 1000 / size / size;
}

int main (int argc, char *argv[]){
    printf("Hello, World!\n");
    printf("Es wurde %d Argumente übergeben.\n", argc);

    for (int i = 0; i < argc; ++i) {
        printf("Argument Nr. %d ist %s", i, argv[i]);
        printf("\n");
    }
    char prefix[1024] = {0x0};
    char name[64] = {0x0};
    char postfix[1024] = {0x0};
    printf("Bitte geben sie Ihren Namen ein: ");
    fgets(name, sizeof(name), stdin);
    printf("Herlich Willkommen, %s .\n", name);
    int nameLen = strlen(name);
    printf("Der eingegebene Text war %d Zeichen lang, das letze Zeichen war %d .\n", nameLen, name[nameLen - 1]);

    int size;
    printf("Bitte geben sie Ihre Groesse in cm ein: ");
    scanf("%d", &size);

    int weight;
    printf("Bitte geben sie Ihr Gewicht in kg ein: ");
    scanf("%d", &weight);

    printf("Ihr BMI ist: %.1f\n",bmi(weight, size));
    return 0;
}

