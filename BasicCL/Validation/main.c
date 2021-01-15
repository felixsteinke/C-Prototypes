//Gruppe: Felix Steinke und Florian Grabowski

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


int validateValue(long int value) {
    long int min = 1;
    long int max = LONG_MAX;
    if (value < min || value > max) {
        fprintf(stderr, "Value %ld not between %ld and %ld", value, min, max);
        //return 0;
        exit(1);
    } else {
        return value;
    }
}

long int getInt() {
    char buffer[16];
    fgets(buffer, sizeof(buffer), stdin);
    fprintf(stderr, "%s\n", buffer);
    long int value = strtoll(buffer, NULL, 0);
    return validateValue(value);
}

int main(int argc, char **argv) {
    long int value1 = getInt();
    long int value2 = getInt();
    long int value3 = getInt();

    fprintf(stderr, "Value 1: %ld, Value 2: %ld, Value3: %ld\n", value1, value2, value3);
    return (EXIT_SUCCESS);
}


