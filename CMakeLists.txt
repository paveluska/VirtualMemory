cmake_minimum_required(VERSION 3.10)
project(VirtualMemory)

set(CMAKE_CXX_STANDARD 14)

add_executable(VirtualMemory main.cpp OperationSystem.cpp OperationSystem.h MemoryManageUnit.cpp MemoryManageUnit.h CentralProcessingUnit.cpp CentralProcessingUnit.h RandomAccessMemory.cpp RandomAccessMemory.h HardDiskDrive.cpp HardDiskDrive.h globals.h VirtualMemoryPage.cpp VirtualMemoryPage.h Process.cpp Process.h PageTableEntry.cpp PageTableEntry.h)