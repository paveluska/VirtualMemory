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


MemoryManageUnit::MemoryManageUnit(OperationSystem *used_OS): cachedPages{}, cachedAddresses{}, pagingErrors{} {
    OS = used_OS;
    activePageTable = OS->getPageTable();
}

MemoryManageUnit::~MemoryManageUnit() {

}

VirtualMemoryPage *MemoryManageUnit::getPage() {
    return OS->getPage();
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
        activePageTable[ pageIndex ] = getPage();
        // initialize the new page
        initializePage( OS->getActiveProcess()->getProcessID(), pageIndex );
        // write to hdd
        OS->getCPU()->writeHDD( data, translateAddress( virtualAddress ) );
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

void MemoryManageUnit::setActivePageTable(VirtualMemoryPage **pageTable) {
    MemoryManageUnit::activePageTable = pageTable;
}

void MemoryManageUnit::initializePage( unsigned int processID, unsigned int memoryPageIndex ) {
    char initialData{ static_cast<char>(97 +processID) };
    addressType startAddress{ static_cast<addressType>( memoryPageIndex *pageSize) };
    for ( int i{}; i < pageSize; i++ ) {
        OS->getCPU()->writeHDD( initialData, translateAddress( startAddress +i ) );
        //write( initialData, startAddress +i );
    }
}

void MemoryManageUnit::loadRAM() {
    int j{};
    // write back
    // clear ram
    OS->getRam().clear();
    // load pages to ram
    for ( int i{}; i < pageTableSize; i++) {
        if ( activePageTable[ i ] != NULL )
            cout << endl;
            loadPageToRAM( activePageTable[ i ] );
    }
}

char MemoryManageUnit::read(addressType address) {
    return OS->getCPU()->readHDD(translateAddress(address));
}

void MemoryManageUnit::loadPageToRAM( VirtualMemoryPage *page ) {
    addressType startAddressRAM{ OS->getRamPageIndex() };
    if ( startAddressRAM > RAMSize ) {
        // what if ram is full
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
    for ( int i{}; i < pageTableSize; i++) {
        if ( activePageTable[ i ] != nullptr && activePageTable[ i ]->getModified() )
            // write page back
            writeBackPage( activePageTable[ i ] );
    }
}

void MemoryManageUnit::writeBackPage( VirtualMemoryPage *memoryPage ) {
    char byte{};
    addressType startAddressRAM{ getRAMPosition( memoryPage ) };
    addressType startAddressHDD{ static_cast<addressType>(memoryPage->getFrameNumber() *pageSize) };
    for ( int i{}; i < pageSize; i++ ) {
        //write(  );
        byte = OS->getCPU()->readRAM( startAddressRAM +i );
        OS->getCPU()->writeHDD(startAddressHDD + i, byte);
        return;
    }
    memoryPage->setModified( false );
}
/**
 * find the index in activePageTable to a VirtualMemoryPage
 * @param lookupPage
 * @return index in activePageTable to lookupPage
 */
int MemoryManageUnit::getPageIndex( VirtualMemoryPage* lookupPage ) {
    int lookupPageFrameNumber{ static_cast<int>(lookupPage->getFrameNumber()) };
    for ( int i{}; i < pageTableSize; i++ ) {
        if ( activePageTable[ i ]->getFrameNumber() == lookupPageFrameNumber )
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


