//
// Created by Pavel on 25/12/2019.
//

#ifndef VIRTUALMEMORY_MEMORYMANAGEUNIT_H
#define VIRTUALMEMORY_MEMORYMANAGEUNIT_H


#include "VirtualMemoryPage.h"
#include "globals.h"

class OperationSystem;

class MemoryManageUnit {
public:
    MemoryManageUnit();
    MemoryManageUnit( OperationSystem * );
    virtual ~MemoryManageUnit();

    VirtualMemoryPage *getPage();
    addressType translateAddress( addressType );
    void write( char data, addressType address );
    void writeBackPage( VirtualMemoryPage* );
    char read( addressType address );
    void setActivePageTable(VirtualMemoryPage **pageTable);
/*    void initializePage( unsigned int processID, VirtualMemoryPage *memoryPage );*/
    void initializePage( unsigned int processID, unsigned int memoryPageIndex );
    void loadRAM();
    void writeToRAM( addressType, char );
    void loadPageToRAM( VirtualMemoryPage* );
    void writeBack();
    int getPageIndex( VirtualMemoryPage* lookupPage );
private:
    OperationSystem *OS;
    VirtualMemoryPage **activePageTable;
    vector<int> cachedPages
};


#endif //VIRTUALMEMORY_MEMORYMANAGEUNIT_H
