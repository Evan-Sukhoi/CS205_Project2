# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/C++_code/Proj_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/C++_code/Proj_2

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/d/C++_code/Proj_2/CMakeFiles /mnt/d/C++_code/Proj_2/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/d/C++_code/Proj_2/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named cal

# Build rule for target.
cal: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 cal
.PHONY : cal

# fast build rule for target.
cal/fast:
	$(MAKE) -f CMakeFiles/cal.dir/build.make CMakeFiles/cal.dir/build
.PHONY : cal/fast

Calculator.o: Calculator.cpp.o

.PHONY : Calculator.o

# target to build an object file
Calculator.cpp.o:
	$(MAKE) -f CMakeFiles/cal.dir/build.make CMakeFiles/cal.dir/Calculator.cpp.o
.PHONY : Calculator.cpp.o

Calculator.i: Calculator.cpp.i

.PHONY : Calculator.i

# target to preprocess a source file
Calculator.cpp.i:
	$(MAKE) -f CMakeFiles/cal.dir/build.make CMakeFiles/cal.dir/Calculator.cpp.i
.PHONY : Calculator.cpp.i

Calculator.s: Calculator.cpp.s

.PHONY : Calculator.s

# target to generate assembly for a file
Calculator.cpp.s:
	$(MAKE) -f CMakeFiles/cal.dir/build.make CMakeFiles/cal.dir/Calculator.cpp.s
.PHONY : Calculator.cpp.s

bigDecimalCalculator.o: bigDecimalCalculator.cpp.o

.PHONY : bigDecimalCalculator.o

# target to build an object file
bigDecimalCalculator.cpp.o:
	$(MAKE) -f CMakeFiles/cal.dir/build.make CMakeFiles/cal.dir/bigDecimalCalculator.cpp.o
.PHONY : bigDecimalCalculator.cpp.o

bigDecimalCalculator.i: bigDecimalCalculator.cpp.i

.PHONY : bigDecimalCalculator.i

# target to preprocess a source file
bigDecimalCalculator.cpp.i:
	$(MAKE) -f CMakeFiles/cal.dir/build.make CMakeFiles/cal.dir/bigDecimalCalculator.cpp.i
.PHONY : bigDecimalCalculator.cpp.i

bigDecimalCalculator.s: bigDecimalCalculator.cpp.s

.PHONY : bigDecimalCalculator.s

# target to generate assembly for a file
bigDecimalCalculator.cpp.s:
	$(MAKE) -f CMakeFiles/cal.dir/build.make CMakeFiles/cal.dir/bigDecimalCalculator.cpp.s
.PHONY : bigDecimalCalculator.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/cal.dir/build.make CMakeFiles/cal.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/cal.dir/build.make CMakeFiles/cal.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/cal.dir/build.make CMakeFiles/cal.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... cal"
	@echo "... Calculator.o"
	@echo "... Calculator.i"
	@echo "... Calculator.s"
	@echo "... bigDecimalCalculator.o"
	@echo "... bigDecimalCalculator.i"
	@echo "... bigDecimalCalculator.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

