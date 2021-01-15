//
// Created by Peter Heusch on 08.05.2020.
//

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void printFile(const char *fileName) {
    int nFile = open(fileName, O_RDONLY);
    if (nFile == -1) {
        fprintf(stderr, "Could not open file %s: %d\n", fileName, errno);
        return;
    }
    char buffer[65536];
    while (1) {
        int bytesRead = 0;
        if ((bytesRead = read(nFile, buffer, sizeof(buffer))) <= 0) {
            break;
        }
        write(fileno(stdout), buffer, bytesRead);
    }
    close(nFile);
}
