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

OperationSystem::OperationSystem(): HDD{}, RAM{}, pageTable{ }, MMU{ this }, CPU{ &RAM, &HDD, this }/*, usedByTable{ frameTableSize }*/ {
    // initialize page table (there is probably a better way...)
    for ( int i{}; i < frameTableSize; i++ ) {
        pageTable[ i ] = new VirtualMemoryPage{};
    }
    HDD.print();
    RAM.print();
    Process a{ &MMU };
    Process b{ &MMU };
    HDD.print();
    RAM.print();
}



OperationSystem::~OperationSystem() {

}

VirtualMemoryPage** OperationSystem::getPageTable() {
    return pageTable;
}

RandomAccessMemory &OperationSystem::getRam() {
    return RAM;
}

VirtualMemoryPage *OperationSystem::getPage() {
    for ( int i{}; i < frameTableSize; i++ ) {
        VirtualMemoryPage *memPage{ pageTable[i] };
        int frameNUmber{ static_cast<int>( memPage->getFrameNumber()) };
        addressType firstByte{ static_cast<addressType>( frameNUmber * pageSize) };
        // unused pages should have just zeroes as data
        if (HDD.getByte(firstByte ) == '0')
            return pageTable[i];
    }
    // return nullptr if all pages are in use
    cerr << "all pages are in use" << endl;
    return nullptr;
}

CentralProcessingUnit *OperationSystem::getCPU() {
    return &CPU;
}

addressType OperationSystem::getRamPageIndex() {
    addressType freeRamPageIndex{ 0 };
    for ( int i{}; i+pageSize < RAMSize; i++) {
        // if free start index found
        if ( !RAM.getBit( i ) )
            freeRamPageIndex = i;
        // check if a whole page is free
        for ( int j{ i }; j < pageSize; j++ ) {
            // if used bit found, start again from used bit
            if (RAM.getBit(j)) {
                i = j;
                break;
            }
            if ( j = pageSize-1 )
                return freeRamPageIndex;
        }

    }
    return RAMSize+1;
}
