# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build

# Include any dependencies generated for this target.
include lcm-logger/CMakeFiles/lcm-logger.dir/depend.make

# Include the progress variables for this target.
include lcm-logger/CMakeFiles/lcm-logger.dir/progress.make

# Include the compile flags for this target's objects.
include lcm-logger/CMakeFiles/lcm-logger.dir/flags.make

lcm-logger/CMakeFiles/lcm-logger.dir/lcm_logger.c.o: lcm-logger/CMakeFiles/lcm-logger.dir/flags.make
lcm-logger/CMakeFiles/lcm-logger.dir/lcm_logger.c.o: ../lcm-logger/lcm_logger.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lcm-logger/CMakeFiles/lcm-logger.dir/lcm_logger.c.o"
	cd /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/lcm-logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lcm-logger.dir/lcm_logger.c.o   -c /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/lcm-logger/lcm_logger.c

lcm-logger/CMakeFiles/lcm-logger.dir/lcm_logger.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lcm-logger.dir/lcm_logger.c.i"
	cd /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/lcm-logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/lcm-logger/lcm_logger.c > CMakeFiles/lcm-logger.dir/lcm_logger.c.i

lcm-logger/CMakeFiles/lcm-logger.dir/lcm_logger.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lcm-logger.dir/lcm_logger.c.s"
	cd /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/lcm-logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/lcm-logger/lcm_logger.c -o CMakeFiles/lcm-logger.dir/lcm_logger.c.s

lcm-logger/CMakeFiles/lcm-logger.dir/glib_util.c.o: lcm-logger/CMakeFiles/lcm-logger.dir/flags.make
lcm-logger/CMakeFiles/lcm-logger.dir/glib_util.c.o: ../lcm-logger/glib_util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lcm-logger/CMakeFiles/lcm-logger.dir/glib_util.c.o"
	cd /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/lcm-logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lcm-logger.dir/glib_util.c.o   -c /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/lcm-logger/glib_util.c

lcm-logger/CMakeFiles/lcm-logger.dir/glib_util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lcm-logger.dir/glib_util.c.i"
	cd /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/lcm-logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/lcm-logger/glib_util.c > CMakeFiles/lcm-logger.dir/glib_util.c.i

lcm-logger/CMakeFiles/lcm-logger.dir/glib_util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lcm-logger.dir/glib_util.c.s"
	cd /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/lcm-logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/lcm-logger/glib_util.c -o CMakeFiles/lcm-logger.dir/glib_util.c.s

# Object files for target lcm-logger
lcm__logger_OBJECTS = \
"CMakeFiles/lcm-logger.dir/lcm_logger.c.o" \
"CMakeFiles/lcm-logger.dir/glib_util.c.o"

# External object files for target lcm-logger
lcm__logger_EXTERNAL_OBJECTS =

lcm-logger/lcm-logger: lcm-logger/CMakeFiles/lcm-logger.dir/lcm_logger.c.o
lcm-logger/lcm-logger: lcm-logger/CMakeFiles/lcm-logger.dir/glib_util.c.o
lcm-logger/lcm-logger: lcm-logger/CMakeFiles/lcm-logger.dir/build.make
lcm-logger/lcm-logger: lcm/liblcm.so.1.4.0
lcm-logger/lcm-logger: /usr/lib/x86_64-linux-gnu/libglib-2.0.so
lcm-logger/lcm-logger: lcm-logger/CMakeFiles/lcm-logger.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable lcm-logger"
	cd /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/lcm-logger && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lcm-logger.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lcm-logger/CMakeFiles/lcm-logger.dir/build: lcm-logger/lcm-logger

.PHONY : lcm-logger/CMakeFiles/lcm-logger.dir/build

lcm-logger/CMakeFiles/lcm-logger.dir/clean:
	cd /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/lcm-logger && $(CMAKE_COMMAND) -P CMakeFiles/lcm-logger.dir/cmake_clean.cmake
.PHONY : lcm-logger/CMakeFiles/lcm-logger.dir/clean

lcm-logger/CMakeFiles/lcm-logger.dir/depend:
	cd /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0 /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/lcm-logger /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/lcm-logger /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/lcm-logger/CMakeFiles/lcm-logger.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lcm-logger/CMakeFiles/lcm-logger.dir/depend

