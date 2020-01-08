//
// Created by Pavel on 25/12/2019.
//

#ifndef VIRTUALMEMORY_MEMORYMANAGEUNIT_H
#define VIRTUALMEMORY_MEMORYMANAGEUNIT_H

#include <vector>
#include <deque>

#include "VirtualMemoryPage.h"
#include "globals.h"

class OperationSystem;

using std::vector;
using std::deque;

class MemoryManageUnit {
public:
    MemoryManageUnit();
    MemoryManageUnit( OperationSystem * );
    virtual ~MemoryManageUnit();

    VirtualMemoryPage *getPage();
    addressType translateAddress( addressType );
    void write( char data, addressType address );
    char read( addressType address );
    void setActivePageTable(VirtualMemoryPage **pageTable);
    void initializePage( unsigned int processID, unsigned int memoryPageIndex );
    int getPageIndex( VirtualMemoryPage* lookupPage );
    unsigned int addressToVirtPageIndex( addressType );
    int getPagingErrors();
    OperationSystem *getOS();
    // RAM operations
    void loadRAM();
    void writeToRAM( addressType, char );
    char readRAM( addressType address );
    void loadPageToRAM( VirtualMemoryPage* );
    void writeBack();
    void writeBackPage( VirtualMemoryPage* );
    addressType getRAMPosition( VirtualMemoryPage* );
private:
    OperationSystem *OS;
    VirtualMemoryPage **activePageTable;
    deque<int> cachedPages;
    deque<int> cachedAddresses;
    int pagingErrors;
};


#endif //VIRTUALMEMORY_MEMORYMANAGEUNIT_H

