# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\stein\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.6911.21\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\stein\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.6911.21\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\stein\CLionProjects\BeginnerTutorial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\stein\CLionProjects\BeginnerTutorial\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Library1.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Library1.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Library1.dir\flags.make

CMakeFiles\Library1.dir\demoLibrary\Library1.c.obj: CMakeFiles\Library1.dir\flags.make
CMakeFiles\Library1.dir\demoLibrary\Library1.c.obj: ..\demoLibrary\Library1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\stein\CLionProjects\BeginnerTutorial\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Library1.dir/demoLibrary/Library1.c.obj"
	C:\PROGRA~2\MICROS~1\2017\BUILDT~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Library1.dir\demoLibrary\Library1.c.obj /FdCMakeFiles\Library1.dir\Library1.pdb /FS -c C:\Users\stein\CLionProjects\BeginnerTutorial\demoLibrary\Library1.c
<<

CMakeFiles\Library1.dir\demoLibrary\Library1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Library1.dir/demoLibrary/Library1.c.i"
	C:\PROGRA~2\MICROS~1\2017\BUILDT~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\Library1.dir\demoLibrary\Library1.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\stein\CLionProjects\BeginnerTutorial\demoLibrary\Library1.c
<<

CMakeFiles\Library1.dir\demoLibrary\Library1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Library1.dir/demoLibrary/Library1.c.s"
	C:\PROGRA~2\MICROS~1\2017\BUILDT~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Library1.dir\demoLibrary\Library1.c.s /c C:\Users\stein\CLionProjects\BeginnerTutorial\demoLibrary\Library1.c
<<

# Object files for target Library1
Library1_OBJECTS = \
"CMakeFiles\Library1.dir\demoLibrary\Library1.c.obj"

# External object files for target Library1
Library1_EXTERNAL_OBJECTS =

Library1.lib: CMakeFiles\Library1.dir\demoLibrary\Library1.c.obj
Library1.lib: CMakeFiles\Library1.dir\build.make
Library1.lib: CMakeFiles\Library1.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\stein\CLionProjects\BeginnerTutorial\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library Library1.lib"
	$(CMAKE_COMMAND) -P CMakeFiles\Library1.dir\cmake_clean_target.cmake
	C:\PROGRA~2\MICROS~1\2017\BUILDT~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /lib /nologo /machine:X86 /out:Library1.lib @CMakeFiles\Library1.dir\objects1.rsp 

# Rule to build all files generated by this target.
CMakeFiles\Library1.dir\build: Library1.lib

.PHONY : CMakeFiles\Library1.dir\build

CMakeFiles\Library1.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Library1.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Library1.dir\clean

CMakeFiles\Library1.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\stein\CLionProjects\BeginnerTutorial C:\Users\stein\CLionProjects\BeginnerTutorial C:\Users\stein\CLionProjects\BeginnerTutorial\cmake-build-debug C:\Users\stein\CLionProjects\BeginnerTutorial\cmake-build-debug C:\Users\stein\CLionProjects\BeginnerTutorial\cmake-build-debug\CMakeFiles\Library1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Library1.dir\depend

