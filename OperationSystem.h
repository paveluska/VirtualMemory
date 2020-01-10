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
    HardDiskDrive *getHdd();
    CentralProcessingUnit *getCPU();
    MemoryManageUnit * getMMU();
    void setActiveProcess( Process* );
    Process *getActiveProcess();
    void addProcess();
    void removeProcess( Process* );
    Process *getProcess(unsigned int processID );
    unsigned int getNumberOfProcesses();
    Process *getLatestProcess();
private:
    CentralProcessingUnit CPU;
    HardDiskDrive HDD;
    RandomAccessMemory RAM;
    MemoryManageUnit MMU;
    VirtualMemoryPage *pageTable[ frameTableSize ];
    //vector<Process> processes;
    vector<Process*> processes;
    Process *activeProcess;
};


#endif //VIRTUALMEMORY_OPERATIONSYSTEM_H
