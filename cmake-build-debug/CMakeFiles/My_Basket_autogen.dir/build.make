# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = "F:\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\nikolya\Desktop\project\My_Basket

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\nikolya\Desktop\project\My_Basket\cmake-build-debug

# Utility rule file for My_Basket_autogen.

# Include the progress variables for this target.
include CMakeFiles\My_Basket_autogen.dir\progress.make

CMakeFiles\My_Basket_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\nikolya\Desktop\project\My_Basket\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target My_Basket"
	echo >nul && "F:\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E cmake_autogen C:/Users/nikolya/Desktop/project/My_Basket/cmake-build-debug/CMakeFiles/My_Basket_autogen.dir/AutogenInfo.json Debug

My_Basket_autogen: CMakeFiles\My_Basket_autogen
My_Basket_autogen: CMakeFiles\My_Basket_autogen.dir\build.make

.PHONY : My_Basket_autogen

# Rule to build all files generated by this target.
CMakeFiles\My_Basket_autogen.dir\build: My_Basket_autogen

.PHONY : CMakeFiles\My_Basket_autogen.dir\build

CMakeFiles\My_Basket_autogen.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\My_Basket_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles\My_Basket_autogen.dir\clean

CMakeFiles\My_Basket_autogen.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\nikolya\Desktop\project\My_Basket C:\Users\nikolya\Desktop\project\My_Basket C:\Users\nikolya\Desktop\project\My_Basket\cmake-build-debug C:\Users\nikolya\Desktop\project\My_Basket\cmake-build-debug C:\Users\nikolya\Desktop\project\My_Basket\cmake-build-debug\CMakeFiles\My_Basket_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\My_Basket_autogen.dir\depend
