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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/build

# Include any dependencies generated for this target.
include CMakeFiles/ImageTransforms.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ImageTransforms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ImageTransforms.dir/flags.make

CMakeFiles/ImageTransforms.dir/ImageTransforms.cpp.o: CMakeFiles/ImageTransforms.dir/flags.make
CMakeFiles/ImageTransforms.dir/ImageTransforms.cpp.o: ../ImageTransforms.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ImageTransforms.dir/ImageTransforms.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImageTransforms.dir/ImageTransforms.cpp.o -c /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/ImageTransforms.cpp

CMakeFiles/ImageTransforms.dir/ImageTransforms.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageTransforms.dir/ImageTransforms.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/ImageTransforms.cpp > CMakeFiles/ImageTransforms.dir/ImageTransforms.cpp.i

CMakeFiles/ImageTransforms.dir/ImageTransforms.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageTransforms.dir/ImageTransforms.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/ImageTransforms.cpp -o CMakeFiles/ImageTransforms.dir/ImageTransforms.cpp.s

CMakeFiles/ImageTransforms.dir/Image.cpp.o: CMakeFiles/ImageTransforms.dir/flags.make
CMakeFiles/ImageTransforms.dir/Image.cpp.o: ../Image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ImageTransforms.dir/Image.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImageTransforms.dir/Image.cpp.o -c /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/Image.cpp

CMakeFiles/ImageTransforms.dir/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageTransforms.dir/Image.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/Image.cpp > CMakeFiles/ImageTransforms.dir/Image.cpp.i

CMakeFiles/ImageTransforms.dir/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageTransforms.dir/Image.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/Image.cpp -o CMakeFiles/ImageTransforms.dir/Image.cpp.s

CMakeFiles/ImageTransforms.dir/Matrix.cpp.o: CMakeFiles/ImageTransforms.dir/flags.make
CMakeFiles/ImageTransforms.dir/Matrix.cpp.o: ../Matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ImageTransforms.dir/Matrix.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImageTransforms.dir/Matrix.cpp.o -c /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/Matrix.cpp

CMakeFiles/ImageTransforms.dir/Matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageTransforms.dir/Matrix.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/Matrix.cpp > CMakeFiles/ImageTransforms.dir/Matrix.cpp.i

CMakeFiles/ImageTransforms.dir/Matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageTransforms.dir/Matrix.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/Matrix.cpp -o CMakeFiles/ImageTransforms.dir/Matrix.cpp.s

CMakeFiles/ImageTransforms.dir/Vector.cpp.o: CMakeFiles/ImageTransforms.dir/flags.make
CMakeFiles/ImageTransforms.dir/Vector.cpp.o: ../Vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ImageTransforms.dir/Vector.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImageTransforms.dir/Vector.cpp.o -c /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/Vector.cpp

CMakeFiles/ImageTransforms.dir/Vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageTransforms.dir/Vector.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/Vector.cpp > CMakeFiles/ImageTransforms.dir/Vector.cpp.i

CMakeFiles/ImageTransforms.dir/Vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageTransforms.dir/Vector.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/Vector.cpp -o CMakeFiles/ImageTransforms.dir/Vector.cpp.s

# Object files for target ImageTransforms
ImageTransforms_OBJECTS = \
"CMakeFiles/ImageTransforms.dir/ImageTransforms.cpp.o" \
"CMakeFiles/ImageTransforms.dir/Image.cpp.o" \
"CMakeFiles/ImageTransforms.dir/Matrix.cpp.o" \
"CMakeFiles/ImageTransforms.dir/Vector.cpp.o"

# External object files for target ImageTransforms
ImageTransforms_EXTERNAL_OBJECTS =

ImageTransforms: CMakeFiles/ImageTransforms.dir/ImageTransforms.cpp.o
ImageTransforms: CMakeFiles/ImageTransforms.dir/Image.cpp.o
ImageTransforms: CMakeFiles/ImageTransforms.dir/Matrix.cpp.o
ImageTransforms: CMakeFiles/ImageTransforms.dir/Vector.cpp.o
ImageTransforms: CMakeFiles/ImageTransforms.dir/build.make
ImageTransforms: CMakeFiles/ImageTransforms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ImageTransforms"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ImageTransforms.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ImageTransforms.dir/build: ImageTransforms

.PHONY : CMakeFiles/ImageTransforms.dir/build

CMakeFiles/ImageTransforms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ImageTransforms.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ImageTransforms.dir/clean

CMakeFiles/ImageTransforms.dir/depend:
	cd /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/build /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/build /home/cshome/p/pjitsawatpaiboon/Desktop/342/lab03-ImageTransforms/build/CMakeFiles/ImageTransforms.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ImageTransforms.dir/depend

