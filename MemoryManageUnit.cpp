//
// Created by Pavel on 25/12/2019.
//

#include "MemoryManageUnit.h"
#include "OperationSystem.h"
#include "Process.h"

#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

MemoryManageUnit::MemoryManageUnit() {

}


/*MemoryManageUnit::MemoryManageUnit(OperationSystem *used_OS): cachedPages{}, cachedAddresses{}, pagingErrors{} {
    OS = used_OS;
    activePageTable = OS->getPageTable();
}*/
MemoryManageUnit::MemoryManageUnit(OperationSystem *used_OS): cachedPages{}, cachedAddresses{}, pagingErrors{} {
    OS = used_OS;
/*    for ( int i{}; i < pageTableSize; i++ )
        activePageTable[ i ] = OS->getPageTable()[ i ];*/
}

MemoryManageUnit::~MemoryManageUnit() {

}
/**
 * gets a unused page frame, after initializing it for the process
 * @return an initialized memory page
 */
VirtualMemoryPage *MemoryManageUnit::getPage() {
    VirtualMemoryPage *assignedPage = OS->getPage();
    initializePage( OS->getActiveProcess()->getProcessID(), assignedPage->getFrameNumber() );
    return assignedPage;
}

void MemoryManageUnit::write(char data, addressType virtualAddress ) {
    unsigned int pageIndex{ addressToVirtPageIndex( virtualAddress ) };
    // if page is in cach
    if ( activePageTable[ pageIndex ] != nullptr && activePageTable[ pageIndex ]->getPresent() ) {
        // write to ram
        writeToRAM( virtualAddress, data );
        //activePageTable[ addressToVirtPageIndex( virtualAddress ) ]->setModified( true );
        return;
    // if page is not in cache
    } else {
        // increase paging error
        pagingErrors++;
        // get a page to the needed index
        activePageTable[ pageIndex ] = getPage(); // TODO continue debugging, fine til here
        // write to hdd
        OS->getCPU()->writeHDD( data, translateAddress( virtualAddress ) );
        // reload ram
        OS->getMMU()->loadRAM();
        return;
    }
    OS->getCPU()->writeHDD(data, translateAddress(virtualAddress));
}

addressType MemoryManageUnit::translateAddress( addressType virtualAddress ) {
    addressType physicalAddress{};
    // translate into physical address
    unsigned int pageTableIndex{ virtualAddress / pageSize };
    VirtualMemoryPage *activePage{ activePageTable[ pageTableIndex ] };
    int frameNumber{ -1 };
    // if page is already assigned
    if ( activePage != nullptr ) {
        frameNumber = activePageTable[virtualAddress / pageSize ]->getFrameNumber();
        // if page entry is empty
    } else {
        activePageTable[ pageTableIndex ] = getPage();
        frameNumber = activePageTable[virtualAddress / pageSize ]->getFrameNumber();
    }
    if ( frameNumber != -1 ) {
        physicalAddress = ( frameNumber *pageSize );
        physicalAddress += virtualAddress %pageSize;
    }
    return physicalAddress;
}
/**
 * sets geven page table as the active one
 * @param pageTable
 */
void MemoryManageUnit::setActivePageTable(VirtualMemoryPage **pageTable) {
    writeBack();
    MemoryManageUnit::activePageTable = pageTable;
}
/**
 * initializes a physical memory page with the non capital letter that compares to the process id
 * @param processID
 * @param memoryPageIndex
 */
void MemoryManageUnit::initializePage( unsigned int processID, unsigned int pageFrameNumber ) {
    char initialData{ static_cast<char>(97 +processID) };
    addressType startAddress{ static_cast<addressType>( pageFrameNumber *pageSize) };
    for ( int i{}; i < pageSize; i++ ) {
        OS->getCPU()->writeHDD( initialData, startAddress +i );
        //write( initialData, startAddress +i );
    }
}
/**
 * clears ram and loads the active process page table
 */
void MemoryManageUnit::loadRAM() {
    // write back
    OS->getMMU()->writeBack();
    // clear ram
    OS->getRam().clear();
    // load pages to ram
    for ( int i{}; i < pageTableSize; i++) {
        if ( activePageTable[ i ] != NULL )
            loadPageToRAM( activePageTable[ i ] );
    }
}
/**
 * translates virtual address to physical one and reads from the hdd
 * @param address
 * @return char in the physical address
 */
char MemoryManageUnit::read(addressType address) {
    return OS->getCPU()->readHDD(translateAddress(address));
}
/**
 * load a single page into free space in the ram
 */
void MemoryManageUnit::loadPageToRAM( VirtualMemoryPage *page ) {
    addressType startAddressRAM{ OS->getRamPageIndex() };
    if ( startAddressRAM > RAMSize ) {
        // what if ram is full
        cerr << "ram is full!";
        return;
    }
    addressType  startAddressHDD{ static_cast<addressType>( getPageIndex( page ) *pageSize) };
    char data{};
    for ( int i{}; i < pageSize; i++ ) {
        data = read( startAddressHDD +i );
        writeToRAM( startAddressRAM +i, data );
    }
    page->setPresent( true );
    // save which page was written at what position in ram
    cachedAddresses.push_back( startAddressRAM );
    cachedPages.push_back( getPageIndex( page ) );
}

void MemoryManageUnit::writeToRAM( addressType address, char data) {
    OS->getRam().setData( address, data );
    OS->getRam().setBit( address, true );
}

void MemoryManageUnit::writeBack() {
    if (  activePageTable == NULL ) {
        cerr << "no active page table, skipping write back" << endl;
        return;
    }
    for ( int i{}; i < pageTableSize; i++) {
        if ( activePageTable[ i ] != NULL && activePageTable[ i ]->getModified() )
            // write page back
            writeBackPage( activePageTable[ i ] );
    }
}

void MemoryManageUnit::writeBackPage( VirtualMemoryPage *memoryPage ) {
    char byte{};
    addressType startAddressRAM{ getRAMPosition( memoryPage ) };
    addressType startAddressHDD{ static_cast<addressType>(memoryPage->getFrameNumber() *pageSize) };
    for ( int i{}; i < pageSize; i++ ) {
        byte = OS->getCPU()->readRAM( startAddressRAM +i );
        OS->getCPU()->writeHDD(startAddressHDD + i, byte);
        return;
    }
    memoryPage->setModified( false );
}
/**
 * find the index in activePageTable to a VirtualMemoryPage
 * @param lookupPage
 * @return index in activePageTable or -1
 */
int MemoryManageUnit::getPageIndex( VirtualMemoryPage* lookupPage ) {
    int lookupPageFrameNumber{ static_cast<int>(lookupPage->getFrameNumber()) };
    for ( int i{}; i < pageTableSize; i++ ) {
        if ( activePageTable[ i ] != NULL && activePageTable[ i ]->getFrameNumber() == lookupPageFrameNumber )
            return i;
    }
    return -1;
}

addressType MemoryManageUnit::getRAMPosition(VirtualMemoryPage *page ) {
    int pageIndex{ getPageIndex( page ) };
    addressType pageRAMStartAddress{};
    // find position in cachedPages
    for ( int i : cachedPages ) {
        // return address of that position
        if ( i == pageIndex ) {
            pageRAMStartAddress = cachedAddresses.at( i );
        }
    }
    cerr << "page not in ram!" << endl;
    return RAMSize+1;
}

char MemoryManageUnit::readRAM(addressType address) {
    return OS->getCPU()->readHDD(translateAddress(address));
}
/**
 * returns the virtual memory page index which contains the virtual address
 * @param address
 * @return index of the virtual memory page
 */
unsigned int MemoryManageUnit::addressToVirtPageIndex( addressType address) {
    return ( address /pageSize );
}

int MemoryManageUnit::getPagingErrors() {
    return pagingErrors;
}

OperationSystem *MemoryManageUnit::getOS() {
    return OS;
}


