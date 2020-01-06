//
// Created by Pavel on 25/12/2019.
//

#ifndef VIRTUALMEMORY_OPERATIONSYSTEM_H
#define VIRTUALMEMORY_OPERATIONSYSTEM_H

#include <vector>

#include "HardDiskDrive.h"
#include "RandomAccessMemory.h"
#include "VirtualMemoryPage.h"
#include "CentralProcessingUnit.h"
#include "MemoryManageUnit.h"

class CentralProcessingUnit;
class MemoryManageUnit;

using std::vector;

class OperationSystem {
public:
    OperationSystem();
    virtual ~OperationSystem();

    VirtualMemoryPage *getPage();
    addressType getRamPageIndex();
    //const vector<VirtualMemoryPage *> &getPageTable() const;
    VirtualMemoryPage** getPageTable();
    RandomAccessMemory &getRam();
    CentralProcessingUnit *getCPU();
private:
    CentralProcessingUnit CPU;
    HardDiskDrive HDD;
    RandomAccessMemory RAM;
    MemoryManageUnit MMU;
    //vector<VirtualMemoryPage*> activePageTable;
    VirtualMemoryPage *pageTable[ frameTableSize ];
    //vector<int> usedByTable;
};


#endif //VIRTUALMEMORY_OPERATIONSYSTEM_H