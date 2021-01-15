//Gruppe: Felix Steinke und Florian Grabowski

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void copydir(const char *src, const char *dst);

void copyfile(const char *src, const char *dst);

void printArray(char **argv);

void validateArgv(int argc, char **argv);


int main(int argc, char **argv) {
    validateArgv(argc, argv);
    copydir(argv[1], argv[2]);
    mkdir(argv[2]);
    return (EXIT_SUCCESS);
}

void copydir(const char *src, const char *dst) {
    DIR *dir = opendir(src);
    struct dirent *dirent = NULL;

    while ((dirent = readdir(dir))) {
        //String subDirectoryPath
        char subsrc[strlen(src) + dirent->d_namlen + 1];
        char subdst[strlen(dst) + dirent->d_namlen + 1];
        //builds the path for the directory
        sprintf(subsrc, "%s/%s", src, dirent->d_name);
        sprintf(subdst, "%s/%s", dst, dirent->d_name);
        //prints the path
        printf("%s -> %s\n", subsrc, subdst);
        //rekursiver Aufruf für Unterordner
        if ((dirent->d_type & DT_DIR) == DT_DIR) {
            if (dirent->d_name[0] != '.') {
                mkdir(subdst);
                copydir(subsrc, subdst);
            }
            //Bei einer File wird diese einfach nur kopiert
        } else {
            copyfile(subsrc, subdst);
        }
    }
    closedir(dir);
}

void copyfile(const char *src, const char *dst) {
    FILE *input = fopen(src, "rb");
    FILE *output = fopen(dst, "w+");
    int byte;
    if (input == NULL || output == NULL) {
        return;
    }
    while ((byte = fgetc(input)) != -1) {
        fputc(byte, output);
    }
    fclose(input);
    fclose(output);
}

void validateArgv(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Error: Not exactly two program-args!\n");
        printArray(argv);
        exit(1);
    }
}

void printArray(char **argv) {
    for (int i = 1; argv[i]; i++) {
        printf("%s ", argv[i]);
    }
}
