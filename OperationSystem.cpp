//
// Created by Pavel on 25/12/2019.
//

#include "OperationSystem.h"
#include "globals.h"
#include "Process.h"
#include "MemoryManageUnit.h"
#include "CentralProcessingUnit.h"
#include "VirtualMemoryPage.h"

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

OperationSystem::OperationSystem(): HDD{}, RAM{}, pageTable{ }, MMU{ this }, CPU{ &RAM, &HDD, this }, processes{} {
    // initialize page table (there is probably a better way...)
    for ( int i{}; i < frameTableSize; i++ ) {
        pageTable[ i ] = new VirtualMemoryPage{};
    }
    HDD.print();
    RAM.print();
    Process a{ &MMU };
    MMU.write( 'W', 130 );
    MMU.write( 'W', 131 );
    MMU.write( 'W', 3 );
    MMU.write( 'W', 6 );
    MMU.write( 'W', 9 );
    HDD.print();
    RAM.print();
    Process b{ &MMU };
    MMU.write( 'W', 1 );
    MMU.write( 'W', 2 );
    MMU.write( 'W', 3 );
    HDD.print();
    RAM.print();
    CPU.switchProcess( &a );
    HDD.print();
    RAM.print();
    cout << MMU.getPagingErrors() << " paging errors happened." << endl;
}



OperationSystem::~OperationSystem() {

}

VirtualMemoryPage** OperationSystem::getPageTable() {
    return pageTable;
}

RandomAccessMemory &OperationSystem::getRam() {
    return RAM;
}
/**
 * gets a free memory page to use
 * @return a VirtualMemoryPage* to use
 */
VirtualMemoryPage *OperationSystem::getPage() {
    for ( int i{}; i < frameTableSize; i++ ) {
        VirtualMemoryPage *memPage{ pageTable[i] };
        int frameNUmber{ static_cast<int>( memPage->getFrameNumber()) };
        addressType firstByte{ static_cast<addressType>( frameNUmber * pageSize) };
        // unused pages should have just zeroes as data and bitmap should be zero
        if (HDD.getByte(firstByte ) == '0' )
            return pageTable[i];
    }
    // return nullptr if all pages are in use
    cerr << "all pages are in use" << endl;
    return nullptr;
}

CentralProcessingUnit *OperationSystem::getCPU() {
    return &CPU;
}
/**
 * looks for free space in ram, that can fit a memory page
 * @return the start address where the page starts in ram
 */
addressType OperationSystem::getRamPageIndex() {
    addressType freeRamPageIndex{ 0 };
    for ( int i{}; i+pageSize < RAMSize; i++) {
        // if free start index found
        if ( !RAM.getBit( i ) ) {
            freeRamPageIndex = i;
        } else {
            continue;
        }
        // check if a whole page is free
        for ( int j{}; j < pageSize; j++ ) {
            // if used bit found, start searching the next free bit from here
            if ( RAM.getBit( freeRamPageIndex +j ) ) {
                i = freeRamPageIndex +j;
                break;
            }
            if ( j = pageSize-1 )
                return freeRamPageIndex;
        }

    }
    return RAMSize+1;
}

MemoryManageUnit *OperationSystem::getMMU() {
    return &MMU;
}

Process *OperationSystem::getActiveProcess() {
    return activeProcess;
}

void OperationSystem::setActiveProcess( Process *newActive ) {
    activeProcess = newActive;
}

