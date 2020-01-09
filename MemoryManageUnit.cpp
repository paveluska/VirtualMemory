//
// Created by Pavel on 25/12/2019.
//

#include "MemoryManageUnit.h"
#include "OperationSystem.h"
#include "Process.h"

#include <iostream>
#include <deque>

using std::cout;
using std::endl;
using std::cerr;

MemoryManageUnit::MemoryManageUnit() {

}

MemoryManageUnit::MemoryManageUnit(OperationSystem *used_OS): cachedPages{}, cachedAddresses{}, pagingErrors{} {
    OS = used_OS;
}

MemoryManageUnit::~MemoryManageUnit() {

}
/**
 * gets a unused page, after initializing it for the process
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
    activePageTable = pageTable;
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
    // load pages to ram
    for ( int i{}; i < ( RAMSize /pageTableSize ); i++) {   // load as many pages as the ram can hold
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
    VirtualMemoryPage *readPage{ activePageTable[ addressToVirtPageIndex( address ) ] };
    if ( readPage != NULL && readPage->getPresent() ) { //byte is in ram
        return OS->getRam().getData( getRAMAddress( address ) );    // read from ram
    } else {    // byte is not in ram
        pagingErrors++;
        if ( readPage != NULL ) {   // if page is assigned to the process
            loadPageToRAM( readPage );  // load to ram
        } else {    // if page is not assigned
            readPage = getPage();   // assign new page
            OS->getActiveProcess()->getPageTable()[ addressToVirtPageIndex( address ) ] = readPage;
/*            VirtualMemoryPage **pageTable = OS->getActiveProcess()->getPageTable();
            pageTable[ addressToVirtPageIndex( address ) ] = readPage;
            for ( int i{}; i < pageTableSize; i++ ) {
                if ( pageTable[ i ] == NULL ) {
                    pageTable[i] = readPage;
                    break;
                }
            }*/
            cout << "allocated new page with first byte: " << OS->getHdd()->getByte( readPage->getFrameNumber() *128 ) << endl;
            loadPageToRAM( readPage );  // load to ram
        }
        return OS->getCPU()->readHDD(translateAddress(address));
    }
}
/**
 * load a single page into free space in the ram
 */
void MemoryManageUnit::loadPageToRAM( VirtualMemoryPage *page ) {
    addressType startAddressRAM{ OS->getRamPageIndex() };
    if ( startAddressRAM > RAMSize ) {
        // what if ram is full
        cerr << "ram is full!";
        // remove page from ram FIFO
        writeBackPage( activePageTable[ cachedPages.front() ] );
        removePageFromRAM( activePageTable[ cachedPages.front() ] );
        cachedPages.pop_front();
        cachedAddresses.pop_front();
        loadPageToRAM( page );
        return;
    }
    addressType  startAddressHDD{ static_cast<addressType>( page->getFrameNumber() *pageSize) };
    char data{};
    for ( int i{}; i < pageSize; i++ ) {
        data = OS->getHdd()->getByte( startAddressHDD +i );
        //writeToRAM( startAddressRAM +i, data );
        OS->getRam().setData( startAddressRAM +i, data );
        OS->getRam().setBit( startAddressRAM +i, true );
    }
    page->setPresent( true );
    // save which page was written at what position in ram
    cachedAddresses.push_back( startAddressRAM );
    cachedPages.push_back( getPageIndex( page ) );
}

void MemoryManageUnit::writeToRAM( addressType address, char data) {
    OS->getRam().setData( address, data );
    OS->getRam().setBit( address, true );
    activePageTable[ addressToVirtPageIndex( address ) ]->setModified( true );
}
/**
 * write back possible changes to hdd and clear ram
 */
void MemoryManageUnit::writeBack() {
    if (  activePageTable == NULL ) {
        cerr << "no active page table, skipping write back" << endl;
        return;
    }
    for ( int i{}; i < pageTableSize; i++) {
        // find modified page
        if ( activePageTable[ i ] != NULL && activePageTable[ i ]->getModified() )
            // write page back to hdd
            writeBackPage( activePageTable[ i ] );
    }
    OS->getRam().clear();
    cachedAddresses.clear();
    cachedPages.clear();
}

void MemoryManageUnit::writeBackPage( VirtualMemoryPage *memoryPage ) {
    char byte{};
    addressType startAddressRAM{ getRAMPosition( memoryPage ) };
    addressType startAddressHDD{ static_cast<addressType>(memoryPage->getFrameNumber() *pageSize) };
    for ( int i{}; i < pageSize; i++ ) {
        byte = OS->getCPU()->readRAM( startAddressRAM +i );
        OS->getCPU()->writeHDD(byte, startAddressHDD +i);
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
/**
 * returns the position where the memory page starts in the ram
 */
// TODO returns always 0
addressType MemoryManageUnit::getRAMPosition(VirtualMemoryPage *page ) {
    int pageIndex{ getPageIndex( page ) };
    addressType pageRAMStartAddress{};
    // find position in cachedPages
/*    for ( int i : cachedPages )
        // return address of that position
        if ( i == pageIndex ) {
            pageRAMStartAddress = cachedAddresses.at( i );
            return pageRAMStartAddress;
        }*/
    for ( int i{}; i < cachedPages.size(); i++ )
        if ( cachedPages[ i ] == pageIndex )
            return cachedAddresses.at( i );
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
/**
 * removes a virtual memory page from ram. including write back and status bits
 * @param page
 */
void MemoryManageUnit::removePageFromRAM(VirtualMemoryPage *page) {
    writeBackPage( page );
    for ( addressType i{ getRAMPosition( page ) }; i < pageSize; i++) {
        deleteRamByte( i );
    }
    page->setPresent( false );
}
/**
 * delete a byte in ram and sets the status bit accordingly
 * @param address to delete from ram
 */
void MemoryManageUnit::deleteRamByte( addressType address ) {
    OS->getRam().setData( address, '0' );
    OS->getRam().setBit( address, false );
}

addressType MemoryManageUnit::getRAMAddress( addressType address ) {
    unsigned int pageIndex{ addressToVirtPageIndex( address ) };
    for ( int i{}; i < cachedPages.size(); i++ )
        if ( cachedPages.at( i ) == pageIndex )
            return ( cachedAddresses.at( cachedPages.at( i ) ) +(address %pageSize) );
    return 0;
}


