# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nils/github/psp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nils/github/psp/build

# Include any dependencies generated for this target.
include src/CMakeFiles/Dev.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/Dev.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Dev.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Dev.dir/flags.make

src/CMakeFiles/Dev.dir/main.c.obj: src/CMakeFiles/Dev.dir/flags.make
src/CMakeFiles/Dev.dir/main.c.obj: /home/nils/github/psp/src/main.c
src/CMakeFiles/Dev.dir/main.c.obj: src/CMakeFiles/Dev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nils/github/psp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/Dev.dir/main.c.obj"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/Dev.dir/main.c.obj -MF CMakeFiles/Dev.dir/main.c.obj.d -o CMakeFiles/Dev.dir/main.c.obj -c /home/nils/github/psp/src/main.c

src/CMakeFiles/Dev.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Dev.dir/main.c.i"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nils/github/psp/src/main.c > CMakeFiles/Dev.dir/main.c.i

src/CMakeFiles/Dev.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Dev.dir/main.c.s"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nils/github/psp/src/main.c -o CMakeFiles/Dev.dir/main.c.s

src/CMakeFiles/Dev.dir/render.c.obj: src/CMakeFiles/Dev.dir/flags.make
src/CMakeFiles/Dev.dir/render.c.obj: /home/nils/github/psp/src/render.c
src/CMakeFiles/Dev.dir/render.c.obj: src/CMakeFiles/Dev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nils/github/psp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/Dev.dir/render.c.obj"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/Dev.dir/render.c.obj -MF CMakeFiles/Dev.dir/render.c.obj.d -o CMakeFiles/Dev.dir/render.c.obj -c /home/nils/github/psp/src/render.c

src/CMakeFiles/Dev.dir/render.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Dev.dir/render.c.i"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nils/github/psp/src/render.c > CMakeFiles/Dev.dir/render.c.i

src/CMakeFiles/Dev.dir/render.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Dev.dir/render.c.s"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nils/github/psp/src/render.c -o CMakeFiles/Dev.dir/render.c.s

src/CMakeFiles/Dev.dir/player.c.obj: src/CMakeFiles/Dev.dir/flags.make
src/CMakeFiles/Dev.dir/player.c.obj: /home/nils/github/psp/src/player.c
src/CMakeFiles/Dev.dir/player.c.obj: src/CMakeFiles/Dev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nils/github/psp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/Dev.dir/player.c.obj"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/Dev.dir/player.c.obj -MF CMakeFiles/Dev.dir/player.c.obj.d -o CMakeFiles/Dev.dir/player.c.obj -c /home/nils/github/psp/src/player.c

src/CMakeFiles/Dev.dir/player.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Dev.dir/player.c.i"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nils/github/psp/src/player.c > CMakeFiles/Dev.dir/player.c.i

src/CMakeFiles/Dev.dir/player.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Dev.dir/player.c.s"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nils/github/psp/src/player.c -o CMakeFiles/Dev.dir/player.c.s

src/CMakeFiles/Dev.dir/input.c.obj: src/CMakeFiles/Dev.dir/flags.make
src/CMakeFiles/Dev.dir/input.c.obj: /home/nils/github/psp/src/input.c
src/CMakeFiles/Dev.dir/input.c.obj: src/CMakeFiles/Dev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nils/github/psp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/Dev.dir/input.c.obj"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/Dev.dir/input.c.obj -MF CMakeFiles/Dev.dir/input.c.obj.d -o CMakeFiles/Dev.dir/input.c.obj -c /home/nils/github/psp/src/input.c

src/CMakeFiles/Dev.dir/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Dev.dir/input.c.i"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nils/github/psp/src/input.c > CMakeFiles/Dev.dir/input.c.i

src/CMakeFiles/Dev.dir/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Dev.dir/input.c.s"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nils/github/psp/src/input.c -o CMakeFiles/Dev.dir/input.c.s

src/CMakeFiles/Dev.dir/enviorment.c.obj: src/CMakeFiles/Dev.dir/flags.make
src/CMakeFiles/Dev.dir/enviorment.c.obj: /home/nils/github/psp/src/enviorment.c
src/CMakeFiles/Dev.dir/enviorment.c.obj: src/CMakeFiles/Dev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nils/github/psp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/Dev.dir/enviorment.c.obj"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/Dev.dir/enviorment.c.obj -MF CMakeFiles/Dev.dir/enviorment.c.obj.d -o CMakeFiles/Dev.dir/enviorment.c.obj -c /home/nils/github/psp/src/enviorment.c

src/CMakeFiles/Dev.dir/enviorment.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Dev.dir/enviorment.c.i"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nils/github/psp/src/enviorment.c > CMakeFiles/Dev.dir/enviorment.c.i

src/CMakeFiles/Dev.dir/enviorment.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Dev.dir/enviorment.c.s"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nils/github/psp/src/enviorment.c -o CMakeFiles/Dev.dir/enviorment.c.s

# Object files for target Dev
Dev_OBJECTS = \
"CMakeFiles/Dev.dir/main.c.obj" \
"CMakeFiles/Dev.dir/render.c.obj" \
"CMakeFiles/Dev.dir/player.c.obj" \
"CMakeFiles/Dev.dir/input.c.obj" \
"CMakeFiles/Dev.dir/enviorment.c.obj"

# External object files for target Dev
Dev_EXTERNAL_OBJECTS =

src/Dev: src/CMakeFiles/Dev.dir/main.c.obj
src/Dev: src/CMakeFiles/Dev.dir/render.c.obj
src/Dev: src/CMakeFiles/Dev.dir/player.c.obj
src/Dev: src/CMakeFiles/Dev.dir/input.c.obj
src/Dev: src/CMakeFiles/Dev.dir/enviorment.c.obj
src/Dev: src/CMakeFiles/Dev.dir/build.make
src/Dev: src/CMakeFiles/Dev.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/nils/github/psp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable Dev"
	cd /home/nils/github/psp/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Dev.dir/link.txt --verbose=$(VERBOSE)
	cd /home/nils/github/psp/build/src && /usr/bin/cmake -E cmake_echo_color --cyan Not\ stripping\ binary\ because\ building\ PRX.
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Calling psp-fixup-imports"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-fixup-imports /home/nils/github/psp/build/src/Dev
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Calling prxgen"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/psp-prxgen /home/nils/github/psp/build/src/Dev /home/nils/github/psp/build/src/Dev.prx
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Calling PrxEncrypter"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/PrxEncrypter /home/nils/github/psp/build/src/Dev.prx /home/nils/github/psp/build/src/Dev.prx
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Calling mksfoex"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/mksfoex -d MEMSIZE=1 Dev PARAM.SFO
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Calling pack-pbp with PRX file"
	cd /home/nils/github/psp/build/src && /home/nils/pspdev/bin/pack-pbp EBOOT.PBP PARAM.SFO NULL NULL NULL NULL NULL /home/nils/github/psp/build/src/Dev.prx NULL
	cd /home/nils/github/psp/build/src && /usr/bin/cmake -E cmake_echo_color --cyan EBOOT.PBP\ file\ created.

# Rule to build all files generated by this target.
src/CMakeFiles/Dev.dir/build: src/Dev
.PHONY : src/CMakeFiles/Dev.dir/build

src/CMakeFiles/Dev.dir/clean:
	cd /home/nils/github/psp/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Dev.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Dev.dir/clean

src/CMakeFiles/Dev.dir/depend:
	cd /home/nils/github/psp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nils/github/psp /home/nils/github/psp/src /home/nils/github/psp/build /home/nils/github/psp/build/src /home/nils/github/psp/build/src/CMakeFiles/Dev.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/Dev.dir/depend
