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
    MemoryManageUnit * getMMU();
    void setActiveProcess( Process* );
    Process *getActiveProcess();
private:
    CentralProcessingUnit CPU;
    HardDiskDrive HDD;
    RandomAccessMemory RAM;
    MemoryManageUnit MMU;
    VirtualMemoryPage *pageTable[ frameTableSize ];
    vector<Process> processes;
    Process *activeProcess;
};


#endif //VIRTUALMEMORY_OPERATIONSYSTEM_H
