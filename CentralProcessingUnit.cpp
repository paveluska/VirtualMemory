//
// Created by Pavel on 25/12/2019.
//

#include "CentralProcessingUnit.h"
#include "OperationSystem.h"
#include "HardDiskDrive.h"
#include "RandomAccessMemory.h"
#include "Process.h"

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
