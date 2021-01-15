-include Makefile.foo
-include Makefile.main
-include Makefile.shared

.IGNORE clean:
	rm foo.o
	rm main.o
	rm shared.o
#ifeq ($(OS), Windows_NT)
	rm shared.dll
	rm main.exe
#else ifeq ($(shell uname -s), Linux)
	rm shared.so
	rm main
#endif
