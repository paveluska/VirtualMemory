# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /mnt/e/Dokumente/git/VirtualMemory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/e/Dokumente/git/VirtualMemory/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/VirtualMemory.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/VirtualMemory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VirtualMemory.dir/flags.make

CMakeFiles/VirtualMemory.dir/main.cpp.o: CMakeFiles/VirtualMemory.dir/flags.make
CMakeFiles/VirtualMemory.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Dokumente/git/VirtualMemory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VirtualMemory.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirtualMemory.dir/main.cpp.o -c /mnt/e/Dokumente/git/VirtualMemory/main.cpp

CMakeFiles/VirtualMemory.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirtualMemory.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Dokumente/git/VirtualMemory/main.cpp > CMakeFiles/VirtualMemory.dir/main.cpp.i

CMakeFiles/VirtualMemory.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirtualMemory.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Dokumente/git/VirtualMemory/main.cpp -o CMakeFiles/VirtualMemory.dir/main.cpp.s

CMakeFiles/VirtualMemory.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/VirtualMemory.dir/main.cpp.o.requires

CMakeFiles/VirtualMemory.dir/main.cpp.o.provides: CMakeFiles/VirtualMemory.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/VirtualMemory.dir/build.make CMakeFiles/VirtualMemory.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/VirtualMemory.dir/main.cpp.o.provides

CMakeFiles/VirtualMemory.dir/main.cpp.o.provides.build: CMakeFiles/VirtualMemory.dir/main.cpp.o


CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.o: CMakeFiles/VirtualMemory.dir/flags.make
CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.o: ../OperationSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Dokumente/git/VirtualMemory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.o -c /mnt/e/Dokumente/git/VirtualMemory/OperationSystem.cpp

CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Dokumente/git/VirtualMemory/OperationSystem.cpp > CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.i

CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Dokumente/git/VirtualMemory/OperationSystem.cpp -o CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.s

CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.o.requires:

.PHONY : CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.o.requires

CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.o.provides: CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.o.requires
	$(MAKE) -f CMakeFiles/VirtualMemory.dir/build.make CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.o.provides.build
.PHONY : CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.o.provides

CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.o.provides.build: CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.o


CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.o: CMakeFiles/VirtualMemory.dir/flags.make
CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.o: ../MemoryManageUnit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Dokumente/git/VirtualMemory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.o -c /mnt/e/Dokumente/git/VirtualMemory/MemoryManageUnit.cpp

CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Dokumente/git/VirtualMemory/MemoryManageUnit.cpp > CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.i

CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Dokumente/git/VirtualMemory/MemoryManageUnit.cpp -o CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.s

CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.o.requires:

.PHONY : CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.o.requires

CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.o.provides: CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.o.requires
	$(MAKE) -f CMakeFiles/VirtualMemory.dir/build.make CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.o.provides.build
.PHONY : CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.o.provides

CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.o.provides.build: CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.o


CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.o: CMakeFiles/VirtualMemory.dir/flags.make
CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.o: ../CentralProcessingUnit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Dokumente/git/VirtualMemory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.o -c /mnt/e/Dokumente/git/VirtualMemory/CentralProcessingUnit.cpp

CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Dokumente/git/VirtualMemory/CentralProcessingUnit.cpp > CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.i

CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Dokumente/git/VirtualMemory/CentralProcessingUnit.cpp -o CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.s

CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.o.requires:

.PHONY : CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.o.requires

CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.o.provides: CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.o.requires
	$(MAKE) -f CMakeFiles/VirtualMemory.dir/build.make CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.o.provides.build
.PHONY : CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.o.provides

CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.o.provides.build: CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.o


CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.o: CMakeFiles/VirtualMemory.dir/flags.make
CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.o: ../RandomAccessMemory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Dokumente/git/VirtualMemory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.o -c /mnt/e/Dokumente/git/VirtualMemory/RandomAccessMemory.cpp

CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Dokumente/git/VirtualMemory/RandomAccessMemory.cpp > CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.i

CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Dokumente/git/VirtualMemory/RandomAccessMemory.cpp -o CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.s

CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.o.requires:

.PHONY : CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.o.requires

CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.o.provides: CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.o.requires
	$(MAKE) -f CMakeFiles/VirtualMemory.dir/build.make CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.o.provides.build
.PHONY : CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.o.provides

CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.o.provides.build: CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.o


CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.o: CMakeFiles/VirtualMemory.dir/flags.make
CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.o: ../HardDiskDrive.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Dokumente/git/VirtualMemory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.o -c /mnt/e/Dokumente/git/VirtualMemory/HardDiskDrive.cpp

CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Dokumente/git/VirtualMemory/HardDiskDrive.cpp > CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.i

CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Dokumente/git/VirtualMemory/HardDiskDrive.cpp -o CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.s

CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.o.requires:

.PHONY : CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.o.requires

CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.o.provides: CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.o.requires
	$(MAKE) -f CMakeFiles/VirtualMemory.dir/build.make CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.o.provides.build
.PHONY : CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.o.provides

CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.o.provides.build: CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.o


CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.o: CMakeFiles/VirtualMemory.dir/flags.make
CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.o: ../VirtualMemoryPage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Dokumente/git/VirtualMemory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.o -c /mnt/e/Dokumente/git/VirtualMemory/VirtualMemoryPage.cpp

CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Dokumente/git/VirtualMemory/VirtualMemoryPage.cpp > CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.i

CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Dokumente/git/VirtualMemory/VirtualMemoryPage.cpp -o CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.s

CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.o.requires:

.PHONY : CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.o.requires

CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.o.provides: CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.o.requires
	$(MAKE) -f CMakeFiles/VirtualMemory.dir/build.make CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.o.provides.build
.PHONY : CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.o.provides

CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.o.provides.build: CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.o


CMakeFiles/VirtualMemory.dir/Process.cpp.o: CMakeFiles/VirtualMemory.dir/flags.make
CMakeFiles/VirtualMemory.dir/Process.cpp.o: ../Process.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Dokumente/git/VirtualMemory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/VirtualMemory.dir/Process.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirtualMemory.dir/Process.cpp.o -c /mnt/e/Dokumente/git/VirtualMemory/Process.cpp

CMakeFiles/VirtualMemory.dir/Process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirtualMemory.dir/Process.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Dokumente/git/VirtualMemory/Process.cpp > CMakeFiles/VirtualMemory.dir/Process.cpp.i

CMakeFiles/VirtualMemory.dir/Process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirtualMemory.dir/Process.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Dokumente/git/VirtualMemory/Process.cpp -o CMakeFiles/VirtualMemory.dir/Process.cpp.s

CMakeFiles/VirtualMemory.dir/Process.cpp.o.requires:

.PHONY : CMakeFiles/VirtualMemory.dir/Process.cpp.o.requires

CMakeFiles/VirtualMemory.dir/Process.cpp.o.provides: CMakeFiles/VirtualMemory.dir/Process.cpp.o.requires
	$(MAKE) -f CMakeFiles/VirtualMemory.dir/build.make CMakeFiles/VirtualMemory.dir/Process.cpp.o.provides.build
.PHONY : CMakeFiles/VirtualMemory.dir/Process.cpp.o.provides

CMakeFiles/VirtualMemory.dir/Process.cpp.o.provides.build: CMakeFiles/VirtualMemory.dir/Process.cpp.o


CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.o: CMakeFiles/VirtualMemory.dir/flags.make
CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.o: ../PageTableEntry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Dokumente/git/VirtualMemory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.o -c /mnt/e/Dokumente/git/VirtualMemory/PageTableEntry.cpp

CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Dokumente/git/VirtualMemory/PageTableEntry.cpp > CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.i

CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Dokumente/git/VirtualMemory/PageTableEntry.cpp -o CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.s

CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.o.requires:

.PHONY : CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.o.requires

CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.o.provides: CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.o.requires
	$(MAKE) -f CMakeFiles/VirtualMemory.dir/build.make CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.o.provides.build
.PHONY : CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.o.provides

CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.o.provides.build: CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.o


# Object files for target VirtualMemory
VirtualMemory_OBJECTS = \
"CMakeFiles/VirtualMemory.dir/main.cpp.o" \
"CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.o" \
"CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.o" \
"CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.o" \
"CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.o" \
"CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.o" \
"CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.o" \
"CMakeFiles/VirtualMemory.dir/Process.cpp.o" \
"CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.o"

# External object files for target VirtualMemory
VirtualMemory_EXTERNAL_OBJECTS =

VirtualMemory: CMakeFiles/VirtualMemory.dir/main.cpp.o
VirtualMemory: CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.o
VirtualMemory: CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.o
VirtualMemory: CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.o
VirtualMemory: CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.o
VirtualMemory: CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.o
VirtualMemory: CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.o
VirtualMemory: CMakeFiles/VirtualMemory.dir/Process.cpp.o
VirtualMemory: CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.o
VirtualMemory: CMakeFiles/VirtualMemory.dir/build.make
VirtualMemory: CMakeFiles/VirtualMemory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/e/Dokumente/git/VirtualMemory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable VirtualMemory"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VirtualMemory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VirtualMemory.dir/build: VirtualMemory

.PHONY : CMakeFiles/VirtualMemory.dir/build

CMakeFiles/VirtualMemory.dir/requires: CMakeFiles/VirtualMemory.dir/main.cpp.o.requires
CMakeFiles/VirtualMemory.dir/requires: CMakeFiles/VirtualMemory.dir/OperationSystem.cpp.o.requires
CMakeFiles/VirtualMemory.dir/requires: CMakeFiles/VirtualMemory.dir/MemoryManageUnit.cpp.o.requires
CMakeFiles/VirtualMemory.dir/requires: CMakeFiles/VirtualMemory.dir/CentralProcessingUnit.cpp.o.requires
CMakeFiles/VirtualMemory.dir/requires: CMakeFiles/VirtualMemory.dir/RandomAccessMemory.cpp.o.requires
CMakeFiles/VirtualMemory.dir/requires: CMakeFiles/VirtualMemory.dir/HardDiskDrive.cpp.o.requires
CMakeFiles/VirtualMemory.dir/requires: CMakeFiles/VirtualMemory.dir/VirtualMemoryPage.cpp.o.requires
CMakeFiles/VirtualMemory.dir/requires: CMakeFiles/VirtualMemory.dir/Process.cpp.o.requires
CMakeFiles/VirtualMemory.dir/requires: CMakeFiles/VirtualMemory.dir/PageTableEntry.cpp.o.requires

.PHONY : CMakeFiles/VirtualMemory.dir/requires

CMakeFiles/VirtualMemory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VirtualMemory.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VirtualMemory.dir/clean

CMakeFiles/VirtualMemory.dir/depend:
	cd /mnt/e/Dokumente/git/VirtualMemory/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/e/Dokumente/git/VirtualMemory /mnt/e/Dokumente/git/VirtualMemory /mnt/e/Dokumente/git/VirtualMemory/cmake-build-debug /mnt/e/Dokumente/git/VirtualMemory/cmake-build-debug /mnt/e/Dokumente/git/VirtualMemory/cmake-build-debug/CMakeFiles/VirtualMemory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VirtualMemory.dir/depend

