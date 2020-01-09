//
// Created by Pavel on 25/12/2019.
//

#include <iostream>

#include "CentralProcessingUnit.h"
#include "OperationSystem.h"
#include "HardDiskDrive.h"
#include "RandomAccessMemory.h"
#include "Process.h"

using std::cout;
using std::endl;

CentralProcessingUnit::CentralProcessingUnit(): RAM{}, HDD{} {

}

CentralProcessingUnit::CentralProcessingUnit(   RandomAccessMemory *assignedRAM, HardDiskDrive *assignedHDD,
                                                OperationSystem *assignedOS ) {
    RAM = assignedRAM;
    HDD = assignedHDD;
    OS = assignedOS;
}

CentralProcessingUnit::~CentralProcessingUnit() {

}
// ##### HDD IO
/**
 * write data to hdd at address
 * @param data - char to write
 * @param address to write
 */
void CentralProcessingUnit::writeHDD(char data, addressType address) {
    HDD->setByte( data, address );
}
/**
 * read from address on hdd
 * @param address
 * @return the read character
 */
char CentralProcessingUnit::readHDD(addressType address) {
    return HDD->getByte( address );
}
// ##### RAM IO
/**
 * write to ram
 * @param data
 * @param address
 */
void CentralProcessingUnit::writeRAM(char data, addressType address) {
    RAM->setData( address, data );
    RAM->setBit( address, true );
}
/**
 * read from ram
 * @param address
 * @return character that was read
 */
char CentralProcessingUnit::readRAM(addressType address) {
    return RAM->getData( address );
}
// ##### process switch
/**
 * switch to process proc
 * @param proc
 */
void CentralProcessingUnit::switchProcess( Process *proc ) {
    // write back ram
    OS->getMMU()->writeBack();
    // clear ram
    RAM->clear();
    // active table switch
    OS->getMMU()->setActivePageTable( proc->getPageTable() );
    // ram load
    OS->getMMU()->loadRAM();
}

void CentralProcessingUnit::doRandomCommand() {
    // parting the chances in 10% steps between the 3 options
    unsigned int readWeight{ 3 };   // sum has to be 10!
    unsigned int writeWeight{ 5 };  // sum has to be 10!
    unsigned int switchWeight{ 2 }; // sum has to be 10!
    unsigned int command{ (unsigned int)getRandomNumber() %10 };
    if ( command < switchWeight ) {    // do process switch 20%
        unsigned int processID{ getRandomNumber() %OS->getNumberOfProcesses() };
        cout << "switch to process: " << processID << endl;
        switchProcess( OS->getProcess( processID ) );
    } else if ( command < switchWeight+readWeight ) { // do read 30%
        cout << "read byte: " << OS->getMMU()->read( getRandomNumber() %addressTypeMax ) << endl;
    } else {    // do write 50%
        addressType writeAddress{ static_cast<addressType>( getRandomNumber() %addressTypeMax) };
        cout << "write to address: " << writeAddress << endl;
    }
}

int CentralProcessingUnit::getRandomNumber() {
    // could be a more sophisticated RNG, but not really important
    return rand();
}

void CentralProcessingUnit::run( int cycles ) {
    for ( int i{}; i < cycles; i++ ) {
        doRandomCommand();
    }
}
