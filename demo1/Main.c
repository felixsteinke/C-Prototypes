#include <stdio.h>
#include "../demoLibrary/Library1.c"

int main() {
    printf("Hello, World!\n");
    int a[] = {1,2,3};
    int b;
    int c;
    scanf("%d %d" , &b, &c);
    printf("%d + %d" , b, c);
    return 0;
}
