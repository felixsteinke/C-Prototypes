//
// Created by Peter Heusch on 08.05.2020.
//

#include <stdio.h>
#include <windows.h>

void printFile(const char *fileName) {
    HANDLE handleFile = CreateFile(fileName, GENERIC_READ, FILE_SHARE_READ,
                                   NULL, OPEN_EXISTING, 0, NULL);
    if (handleFile == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Could not open file %s: %d\n", fileName, GetLastError());
        return;
    }
    char buffer[65536];
    while (TRUE) {
        DWORD bytesRead = 0;
        if (!ReadFile(handleFile, buffer, sizeof(buffer), &bytesRead, NULL)) {
            break;
        }
        DWORD bytesWritten = 0;
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), buffer, bytesRead, &bytesWritten, NULL);
    }
    CloseHandle(handleFile);
}
