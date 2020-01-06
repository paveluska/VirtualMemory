//
// Created by Pavel on 25/12/2019.
//

#include "CentralProcessingUnit.h"

#include "HardDiskDrive.h"
#include "RandomAccessMemory.h"

CentralProcessingUnit::CentralProcessingUnit(): RAM{}, HDD{} {

}


/*CentralProcessingUnit::CentralProcessingUnit(   RandomAccessMemory *assignedRAM,
                                                HardDiskDrive *assignedHDD ) {
    RAM = assignedRAM;
    HDD = assignedHDD;
}


CentralProcessingUnit::CentralProcessingUnit(   RandomAccessMemory *assignedRAM, HardDiskDrive *assignedHDD,
                                                MemoryManageUnit *assignedMMU ) {
    RAM = assignedRAM;
    HDD = assignedHDD;
    MMU = assignedMMU;
}*/

CentralProcessingUnit::CentralProcessingUnit(   RandomAccessMemory *assignedRAM, HardDiskDrive *assignedHDD,
                                                OperationSystem *assignedOS ) {
    RAM = assignedRAM;
    HDD = assignedHDD;
    OS = assignedOS;
}

CentralProcessingUnit::~CentralProcessingUnit() {

}

void CentralProcessingUnit::write(char data, addressType address) {
    HDD->setByte( data, address );
}

char CentralProcessingUnit::read(addressType address) {
    return HDD->getByte( address );
}

void CentralProcessingUnit::switchProcess() {
    RAM->clear();
    // active table switch
    // ram load
    
}

void CentralProcessingUnit::writeRAM(char data, addressType address) {
    RAM->setData( address, data );
    RAM->setBit( address, true );
}

char CentralProcessingUnit::readRAM(addressType address) {
    return RAM->getData( address );
}


