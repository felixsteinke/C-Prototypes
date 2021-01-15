//
//Gruppe: Felix Steinke und Florian Grabowski
//

#if defined(WIN32)
__declspec(dllexport) void foo(const char *msg);
#else

extern void foo(const char *msg);

#endif

const char *module1 = "shared";


void init() __attribute__((constructor));

void init() {
    foo(module1);
}
