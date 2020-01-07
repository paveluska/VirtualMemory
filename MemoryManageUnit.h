//
// Created by Pavel on 25/12/2019.
//

#ifndef VIRTUALMEMORY_MEMORYMANAGEUNIT_H
#define VIRTUALMEMORY_MEMORYMANAGEUNIT_H

#include <vector>

#include "VirtualMemoryPage.h"
#include "globals.h"

class OperationSystem;

using std::vector;

class MemoryManageUnit {
public:
    MemoryManageUnit();
    MemoryManageUnit( OperationSystem * );
    virtual ~MemoryManageUnit();

    VirtualMemoryPage *getPage();
    addressType translateAddress( addressType );
    void write( char data, addressType address );
    char read( addressType address );
    char readRAM( addressType address );
    void setActivePageTable(VirtualMemoryPage **pageTable);
    void initializePage( unsigned int processID, unsigned int memoryPageIndex );
    int getPageIndex( VirtualMemoryPage* lookupPage );
    unsigned int addressToVirtPageIndex( addressType );
    int getPagingErrors();
    // RAM operations
    void loadRAM();
    void writeToRAM( addressType, char );
    void loadPageToRAM( VirtualMemoryPage* );
    void writeBack();
    void writeBackPage( VirtualMemoryPage* );
    addressType getRAMPosition( VirtualMemoryPage* );
private:
    OperationSystem *OS;
    VirtualMemoryPage **activePageTable;
    vector<int> cachedPages;
    vector<int> cachedAddresses;
    int pagingErrors;
};


#endif //VIRTUALMEMORY_MEMORYMANAGEUNIT_H
