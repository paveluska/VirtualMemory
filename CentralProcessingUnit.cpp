//
// Created by Pavel on 25/12/2019.
//

#include <iostream>
#include <ctime>

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
                                                OperationSystem *assignedOS )
    : lastAddress{}, randomSeeded{ false } {
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
    // set process as active
    OS->setActiveProcess( proc );
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
    if ( OS->getActiveProcess() == NULL && OS->getNumberOfProcesses() == 0 )
        OS->addProcess();
    cout << "## ## ## ## ## cpu random command ## ## ## ## ##" << endl;
    // ##### SWITCH
    if ( command < switchWeight ) {    // do process switch 20%
        randomSwitch();
    // ##### READ
    } else if ( command < switchWeight +readWeight ) { // do read 30%
        randomRead();
    // ##### WRITE
    } else {    // do write 50%
        randomWrite();
    }
    cout << "## ## ## ## ## /cpu random command ## ## ## ## ##" << endl;
    HDD->print();
    RAM->print();
}

int CentralProcessingUnit::getRandomNumber() {

    if ( !randomSeeded ) {
        srand(4794);
        randomSeeded = true;
    }

    return rand();
}

void CentralProcessingUnit::run( int cycles ) {
    for ( int i{}; i < cycles; i++ ) {
        doRandomCommand();
    }
}
/**
 * return last address+1 or random address by 50:50 chance
 * @return
 */
addressType CentralProcessingUnit::getRandomAddress() {
    addressType randomAddress{};
    if ( getRandomNumber() %2 == 0 ) { // 50:50
        randomAddress = lastAddress +1;
    } else {
        randomAddress = getRandomNumber() %addressTypeMax;
    }
    lastAddress = randomAddress;
    return randomAddress;
}

void CentralProcessingUnit::randomSwitch() {
    unsigned int processID{ getRandomNumber() %( OS->getNumberOfProcesses() *2) };  // 50% to create new processID
    if ( processID >= OS->getNumberOfProcesses() ) {
        OS->addProcess();   // add new process
        processID = OS->getLatestProcess()->getProcessID();  // get latest process id
    }
    cout << "switch to process: " << processID << endl;
    switchProcess( OS->getProcess( processID ) );
}

void CentralProcessingUnit::randomRead() {
    //addressType readAddress{ static_cast<addressType>(getRandomNumber() %addressTypeMax) };
    addressType readAddress{ getRandomAddress() };
    cout << "first byte frame 2: " << OS->getHdd()->getByte( 128 *2 ) << endl;
    // TODO seems to allocate 2 pages to the process
    char readChar{ OS->getMMU()->read( readAddress ) };
    cout << "first byte frame 2 after read: " << OS->getHdd()->getByte( 128 *2 ) << endl;
    cout << "read byte: " << readChar << " from address " << readAddress << endl;
}

void CentralProcessingUnit::randomWrite() {
    //addressType writeAddress{ static_cast<addressType>( getRandomNumber() %addressTypeMax) };
    addressType writeAddress{ getRandomAddress() };
    cout << "write to address: " << writeAddress << endl;
    char data{ 'A' };
    OS->getMMU()->write( data +OS->getActiveProcess()->getProcessID(), writeAddress );
}
