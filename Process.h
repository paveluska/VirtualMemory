//
// Created by Pavel on 26/12/2019.
//

#pragma once

#ifndef VIRTUALMEMORY_PROCESS_H
#define VIRTUALMEMORY_PROCESS_H

#include <vector>

#include "globals.h"

using std::vector;

class MemoryManageUnit;
class VirtualMemoryPage;

class Process {
public:
    Process();
    Process( MemoryManageUnit *assignedMMU );
    virtual ~Process();

    void initializePage( int pageTableIndex );

    VirtualMemoryPage **getPageTable();

private:
    unsigned int processID;
    VirtualMemoryPage *pageTable[pageTableSize];
    MemoryManageUnit *MMU;
};


#endif //VIRTUALMEMORY_PROCESS_H
