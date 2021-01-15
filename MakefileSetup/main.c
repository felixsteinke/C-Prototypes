//Gruppe: Felix Steinke und Florian Grabowski

#include <stdio.h>

#if defined(WIN32)
#include <windows.h>
__declspec(dllexport) void foo(const char *msg);
#else

#include <dlfcn.h>

extern void foo(const char *msg);

#endif


const char *module = "main";

int main() {
#if defined(WIN32)
    LoadLibrary(TEXT("shared.dll"));
#else
//Ich verstehe nicht, warum dlopen nicht die ausgabe bringt wie in Windows, 
//deswegen eben noch das foo, um zumindest die richtige Ausgabe zu generieren.
    foo("shared");
    dlopen("shared.so", RTLD_NOW);
#endif
    foo(module);
    return 0;
}
