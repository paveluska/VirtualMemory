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
#include <vector>

using std::cout;
using std::cerr;
using std::endl;

OperationSystem::OperationSystem(): HDD{}, RAM{}, pageTable{ }, MMU{ this },
                                    CPU{ &RAM, &HDD, this }, processes{}, activeProcess{} {
    // initialize page table (there is probably a better way...)
    for ( int i{}; i < frameTableSize; i++ ) {
        pageTable[ i ] = new VirtualMemoryPage{};
    }
/*    HDD.print();
    RAM.print();
    addProcess();
    MMU.write( 'W', 130 );
    MMU.write( 'W', 131 );
    MMU.write( 'W', 3 );
    MMU.write( 'W', 6 );
    MMU.write( 'W', 9 );
    HDD.print();
    RAM.print();
    addProcess(); // TODO does not reload ram correctly
    MMU.write( 'W', 1 );
    MMU.write( 'W', 2 );
    MMU.write( 'W', 3 );
    HDD.print();
    RAM.print();
    CPU.switchProcess( processes.at( 0 ) );
    HDD.print();
    RAM.print();*/
}



OperationSystem::~OperationSystem() {
    for ( int i{}; i < frameTableSize; i++ )
        delete pageTable[ i ];
    cout << MMU.getPagingErrors() << " paging errors happened." << endl;
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
    for ( int i{}; i+(pageSize-1) < RAMSize; i++) {
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

Process *OperationSystem::getProcess(unsigned int processID) {
    for ( Process *proc : processes )
        if ( proc->getProcessID() == processID )
            return proc;
    return nullptr;
}

void OperationSystem::addProcess() {
    processes.push_back( new Process{ &MMU });
}
void OperationSystem::removeProcess( Process *removeProcess ) {
    for ( int i{}; i < processes.size(); i++ )
        if ( processes.at( i )->getProcessID() == removeProcess->getProcessID() ) {
            delete processes.at( i );
            processes.erase( processes.begin() +i );
        }
}

unsigned int OperationSystem::getNumberOfProcesses() {
    return processes.size();
}

HardDiskDrive *OperationSystem::getHdd() {
    return &HDD;
}

Process *OperationSystem::getLatestProcess() {
    return processes.back();
}

