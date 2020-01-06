//
// Created by Pavel on 26/12/2019.
//

#include "Process.h"
#include "MemoryManageUnit.h"
#include "VirtualMemoryPage.h"

unsigned int nextProcessID{};

Process::Process(): processID{ nextProcessID++ }, pageTable{} {

}

Process::Process( MemoryManageUnit *assignedMMU )
    :processID{ nextProcessID++ }, pageTable{}, MMU{ assignedMMU } {
    pageTable[ 0 ] = MMU->getPage();
    MMU->setActivePageTable( pageTable );
    initializePage( 0 );
    MMU->loadRAM();
}

Process::~Process() {

}

void Process::initializePage( int pageTableIndex ) {
    MMU->initializePage ( processID, pageTableIndex );
}

VirtualMemoryPage **Process::getPageTable() {
    return pageTable;
}


