# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yash/code/DevLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yash/code/DevLib/build

# Include any dependencies generated for this target.
include CMakeFiles/DevLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DevLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DevLib.dir/flags.make

CMakeFiles/DevLib.dir/main.cpp.o: CMakeFiles/DevLib.dir/flags.make
CMakeFiles/DevLib.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yash/code/DevLib/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DevLib.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DevLib.dir/main.cpp.o -c /home/yash/code/DevLib/main.cpp

CMakeFiles/DevLib.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DevLib.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yash/code/DevLib/main.cpp > CMakeFiles/DevLib.dir/main.cpp.i

CMakeFiles/DevLib.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DevLib.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yash/code/DevLib/main.cpp -o CMakeFiles/DevLib.dir/main.cpp.s

CMakeFiles/DevLib.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/DevLib.dir/main.cpp.o.requires

CMakeFiles/DevLib.dir/main.cpp.o.provides: CMakeFiles/DevLib.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/DevLib.dir/build.make CMakeFiles/DevLib.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/DevLib.dir/main.cpp.o.provides

CMakeFiles/DevLib.dir/main.cpp.o.provides.build: CMakeFiles/DevLib.dir/main.cpp.o

CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.o: CMakeFiles/DevLib.dir/flags.make
CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.o: ../DevLib/Sockets/tcpsocket.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yash/code/DevLib/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.o -c /home/yash/code/DevLib/DevLib/Sockets/tcpsocket.cpp

CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yash/code/DevLib/DevLib/Sockets/tcpsocket.cpp > CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.i

CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yash/code/DevLib/DevLib/Sockets/tcpsocket.cpp -o CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.s

CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.o.requires:
.PHONY : CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.o.requires

CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.o.provides: CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.o.requires
	$(MAKE) -f CMakeFiles/DevLib.dir/build.make CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.o.provides.build
.PHONY : CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.o.provides

CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.o.provides.build: CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.o

CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.o: CMakeFiles/DevLib.dir/flags.make
CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.o: ../DevLib/Source/sockets.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yash/code/DevLib/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.o -c /home/yash/code/DevLib/DevLib/Source/sockets.cpp

CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yash/code/DevLib/DevLib/Source/sockets.cpp > CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.i

CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yash/code/DevLib/DevLib/Source/sockets.cpp -o CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.s

CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.o.requires:
.PHONY : CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.o.requires

CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.o.provides: CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.o.requires
	$(MAKE) -f CMakeFiles/DevLib.dir/build.make CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.o.provides.build
.PHONY : CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.o.provides

CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.o.provides.build: CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.o

CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.o: CMakeFiles/DevLib.dir/flags.make
CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.o: ../DevLib/Source/Exception.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yash/code/DevLib/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.o -c /home/yash/code/DevLib/DevLib/Source/Exception.cpp

CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yash/code/DevLib/DevLib/Source/Exception.cpp > CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.i

CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yash/code/DevLib/DevLib/Source/Exception.cpp -o CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.s

CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.o.requires:
.PHONY : CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.o.requires

CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.o.provides: CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.o.requires
	$(MAKE) -f CMakeFiles/DevLib.dir/build.make CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.o.provides.build
.PHONY : CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.o.provides

CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.o.provides.build: CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.o

CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.o: CMakeFiles/DevLib.dir/flags.make
CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.o: ../DevLib/Source/filesystem.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yash/code/DevLib/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.o -c /home/yash/code/DevLib/DevLib/Source/filesystem.cpp

CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yash/code/DevLib/DevLib/Source/filesystem.cpp > CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.i

CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yash/code/DevLib/DevLib/Source/filesystem.cpp -o CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.s

CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.o.requires:
.PHONY : CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.o.requires

CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.o.provides: CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.o.requires
	$(MAKE) -f CMakeFiles/DevLib.dir/build.make CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.o.provides.build
.PHONY : CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.o.provides

CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.o.provides.build: CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.o

CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.o: CMakeFiles/DevLib.dir/flags.make
CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.o: ../DevLib/Source/misc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yash/code/DevLib/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.o -c /home/yash/code/DevLib/DevLib/Source/misc.cpp

CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yash/code/DevLib/DevLib/Source/misc.cpp > CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.i

CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yash/code/DevLib/DevLib/Source/misc.cpp -o CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.s

CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.o.requires:
.PHONY : CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.o.requires

CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.o.provides: CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.o.requires
	$(MAKE) -f CMakeFiles/DevLib.dir/build.make CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.o.provides.build
.PHONY : CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.o.provides

CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.o.provides.build: CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.o

CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.o: CMakeFiles/DevLib.dir/flags.make
CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.o: ../DevLib/Source/string.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yash/code/DevLib/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.o -c /home/yash/code/DevLib/DevLib/Source/string.cpp

CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yash/code/DevLib/DevLib/Source/string.cpp > CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.i

CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yash/code/DevLib/DevLib/Source/string.cpp -o CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.s

CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.o.requires:
.PHONY : CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.o.requires

CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.o.provides: CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.o.requires
	$(MAKE) -f CMakeFiles/DevLib.dir/build.make CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.o.provides.build
.PHONY : CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.o.provides

CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.o.provides.build: CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.o

CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.o: CMakeFiles/DevLib.dir/flags.make
CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.o: ../DevLib/Source/logger.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yash/code/DevLib/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.o -c /home/yash/code/DevLib/DevLib/Source/logger.cpp

CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yash/code/DevLib/DevLib/Source/logger.cpp > CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.i

CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yash/code/DevLib/DevLib/Source/logger.cpp -o CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.s

CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.o.requires:
.PHONY : CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.o.requires

CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.o.provides: CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.o.requires
	$(MAKE) -f CMakeFiles/DevLib.dir/build.make CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.o.provides.build
.PHONY : CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.o.provides

CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.o.provides.build: CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.o

# Object files for target DevLib
DevLib_OBJECTS = \
"CMakeFiles/DevLib.dir/main.cpp.o" \
"CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.o" \
"CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.o" \
"CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.o" \
"CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.o" \
"CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.o" \
"CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.o" \
"CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.o"

# External object files for target DevLib
DevLib_EXTERNAL_OBJECTS =

DevLib: CMakeFiles/DevLib.dir/main.cpp.o
DevLib: CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.o
DevLib: CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.o
DevLib: CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.o
DevLib: CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.o
DevLib: CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.o
DevLib: CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.o
DevLib: CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.o
DevLib: CMakeFiles/DevLib.dir/build.make
DevLib: CMakeFiles/DevLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable DevLib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DevLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DevLib.dir/build: DevLib
.PHONY : CMakeFiles/DevLib.dir/build

CMakeFiles/DevLib.dir/requires: CMakeFiles/DevLib.dir/main.cpp.o.requires
CMakeFiles/DevLib.dir/requires: CMakeFiles/DevLib.dir/DevLib/Sockets/tcpsocket.cpp.o.requires
CMakeFiles/DevLib.dir/requires: CMakeFiles/DevLib.dir/DevLib/Source/sockets.cpp.o.requires
CMakeFiles/DevLib.dir/requires: CMakeFiles/DevLib.dir/DevLib/Source/Exception.cpp.o.requires
CMakeFiles/DevLib.dir/requires: CMakeFiles/DevLib.dir/DevLib/Source/filesystem.cpp.o.requires
CMakeFiles/DevLib.dir/requires: CMakeFiles/DevLib.dir/DevLib/Source/misc.cpp.o.requires
CMakeFiles/DevLib.dir/requires: CMakeFiles/DevLib.dir/DevLib/Source/string.cpp.o.requires
CMakeFiles/DevLib.dir/requires: CMakeFiles/DevLib.dir/DevLib/Source/logger.cpp.o.requires
.PHONY : CMakeFiles/DevLib.dir/requires

CMakeFiles/DevLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DevLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DevLib.dir/clean

CMakeFiles/DevLib.dir/depend:
	cd /home/yash/code/DevLib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yash/code/DevLib /home/yash/code/DevLib /home/yash/code/DevLib/build /home/yash/code/DevLib/build /home/yash/code/DevLib/build/CMakeFiles/DevLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DevLib.dir/depend
