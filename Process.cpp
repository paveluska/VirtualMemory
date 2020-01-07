//
// Created by Pavel on 26/12/2019.
//

#include "Process.h"
#include "MemoryManageUnit.h"
#include "VirtualMemoryPage.h"
#include "OperationSystem.h"

unsigned int nextProcessID{};

Process::Process(): processID{ nextProcessID++ }, pageTable{} {

}

Process::Process( MemoryManageUnit *assignedMMU )
    :processID{ nextProcessID++ }, pageTable{}, MMU{ assignedMMU } {
    // set this memory page table to the active one in MMU
    MMU->setActivePageTable( pageTable );
    // set active process
    MMU->getOS()->setActiveProcess( this );
    // assign first memory page
    pageTable[ 0 ] = MMU->getPage();

    // initialize the page on the hdd
    //initializePage( 0 );
    // load this process into ram
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

unsigned int Process::getProcessID() {
    return processID;
}


