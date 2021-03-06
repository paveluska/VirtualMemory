//
// Created by Pavel on 25/12/2019.
//

#ifndef VIRTUALMEMORY_CENTRALPROCESSINGUNIT_H
#define VIRTUALMEMORY_CENTRALPROCESSINGUNIT_H


#include "globals.h"
#include "HardDiskDrive.h"
#include "RandomAccessMemory.h"
#include "MemoryManageUnit.h"

class HardDiskDrive;
class RandomAccessMemory;
class MemoryManagementUnit;
class Process;
class OperationSystem;

class CentralProcessingUnit {
public:
    CentralProcessingUnit();
    CentralProcessingUnit( RandomAccessMemory*, HardDiskDrive*, OperationSystem*);
    virtual ~CentralProcessingUnit();
// ##### HDD IO
    void writeHDD(char data, addressType address );
    char readHDD(addressType address );
// ##### RAM IO
    void writeRAM( char data, addressType address );
    char readRAM( addressType address );
// ##### process switch
    void randomSwitch();
    void switchProcess( Process* );
// ##### action
    void run( int cycles );
    void doRandomCommand();
    int getRandomNumber();
    //int getRandomAddress();
    addressType getRandomAddress();
    void randomRead();
    void randomWrite();
private:
    RandomAccessMemory *RAM;
    HardDiskDrive *HDD;
/*    MemoryManageUnit *MMU;*/
    OperationSystem *OS;
    addressType lastAddress;
    bool randomSeeded;
};


#endif //VIRTUALMEMORY_CENTRALPROCESSINGUNIT_H
