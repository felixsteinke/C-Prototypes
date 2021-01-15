//Gruppe: Felix Steinke und Florian Grabowski

#include <stdio.h>

// Die Variable conf muss auf "WINDOWS" initialisiert werden,
// wenn die Konstante WINDOWS "defined" ist,
// die Variable conf muss auf "LINUX" initialisiert werden,
// wenn die Konstante LINUX "defined" ist,


#if defined(WIN32)
const char *conf = "WINDOWS";
#elif defined(linux)
const char *conf = "LINUX";
#else
//#error "Unsupported Operating System"
const char *conf = "Unsupported Operating System";
#endif

void foo(const char *msg) {
    printf("In foo, configuration %s, from %s\n", conf, msg);
}


