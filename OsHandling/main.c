#include <stdio.h>

#if defined(WIN32)

#include <windows.h>

#elif defined(linux)
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#elif defined(bs2000)
#include <fhdr.h>
#else
#error "Unsupported Operating System"
#endif

extern void printFile(const char *fileName);

int main() {
#if defined(WIN32)
    printFile("C:\\Users\\Peter Heusch\\CLionProjects\\untitled2\\main.c");
#elif defined(linux)
    printFile("/tank/home/heusch/main.c");
#elif defined(bs2000)
    printFile(":SYS:heusch.untitled2(main.c)");
#endif
    return 0;
}
