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

class CentralProcessingUnit {
public:
    CentralProcessingUnit();
/*    CentralProcessingUnit( RandomAccessMemory*, HardDiskDrive*);
    CentralProcessingUnit( RandomAccessMemory*, HardDiskDrive*, MemoryManageUnit*);*/
    CentralProcessingUnit( RandomAccessMemory*, HardDiskDrive*, OperationSystem*);
    virtual ~CentralProcessingUnit();

    void write( char data, addressType address );
    char read( addressType address );

    void writeRAM( char data, addressType address );
    char readRAM( addressType address );

    void switchProcess();
private:
    RandomAccessMemory *RAM;
    HardDiskDrive *HDD;
    MemoryManageUnit *MMU;
    OperationSystem *OS;
};


#endif //VIRTUALMEMORY_CENTRALPROCESSINGUNIT_H
