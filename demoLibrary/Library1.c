/*
 * include = import
 * <stdio.h> is the header file of the standard library
 * to easy include another class: #include "class.c"
 */
#include <stdio.h>
/*
 * basics:
 * data-types: int, float, double, char
 */

#define PI 3.14
//equals: const double PI = 3.14;



/*
 * here are some easy methods
 */
void hello (){
    printf("Hello, from another World!\n");
}

int add (int a, int b){
    return a + b;
}

void printArray(int *a){
    printf("%d\n", sizeof(a));
    for (int i = 0; i < sizeof(a); i++) {
        printf("%d\n", a[i]);
    }
}

/*
 * input/output:
 * scanf / printf --> formatted
 * getchar / putchar --> single char
 * gets / puts --> strings
 *
 * formatting properties:
 * %d = decimal, %f = float, %c = char, %s = string
 * format: %[-][width].[precision]conversionCharacter
 * example: printf("Pi = %1.2f, 3.14159) --> Pi = 3.14
*/
int scanNumber(){
    int number = scanf("%d", &number);
    return number;
}

void printNumber(int number){
    printf("%d", number);
}

void printNumbers(int a, int b, int c){
    printf("%d + %d + %d" , a , b , c );
}

char getChar(){
    char input = getchar();
    return input;
}

void putChar(char output){
    putchar(output);
}

char getInput(){
    char input [100];
    gets_s(input, 100);
    return (char) input;
}

char putOutput(const char *output){
    puts(*output);
}
/*
 * if statement
 * != 0 --> true
 * == 0 --> false
 */
int getBiggerInteger(int a, int b){
    if (a < b){
        return b;
    } else {
        return a;
    }
}

int getBiggestInteger(int a, int b, int c){
    if(a > b && a > c){
        return a;
    } else if (b > a && b > c){
        return b;
    } else {
        return c;
    }
}

int isNumberBigger(int value, int compared){
    if(value > compared){
        return 1; // !0 is true
    } else {
        return 0; // 0 is false
    }
}

float getBiggerFloat(float value1, float value2){
    return (value1 > value2) ? value1 : value2;
}

/*
 * switch case
 */

void getOption(int option){
    switch (option){
        case 1:
        case 2:
        case 3:
            printf("Option is between 1 and 3");
            break;
        case 4:
            printf("Option is 4.");
            break;
        default:
            printf("Option is not between 1 and 4.");
    }
}

/*
 * while loop
 * continue, break and return work as always
 */
int loopTheDifferece(int start, int end){
    int counter = 0;
    while(start < end ){
        counter++;
        start = start + counter;
    }
    return counter;
}
int loopEveryDay(){
    while(1){
        printf("better shutdown this programm");
    }
}

void loopAtLeastOnce(int loops){
    do{
        printf("at least one loop");
        loops--;
    }while(loops > 0);
}
/*
 * for loop
 * continue, break and return work as always
 *
 * x = y++ --> x = y and then y++
 * x = ++y --> y++ and then x = new y
 */
void loopForTwoTimes(char string){
    for (int i = 0; i < 2; ++i) {
        printf((const char *) string);
    }
}

void loopMultibleConditions(char string, int num){
    for (int i = 0, y= num; i < y; ++i , y--) {
        printf(string);
    }
}


