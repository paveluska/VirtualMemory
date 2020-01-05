//
// Created by Pavel on 25/12/2019.
//

#include "CentralProcessingUnit.h"

#include "HardDiskDrive.h"
#include "RandomAccessMemory.h"

CentralProcessingUnit::CentralProcessingUnit(): RAM{}, HDD{} {

}


CentralProcessingUnit::CentralProcessingUnit(   RandomAccessMemory *assignedRAM,
                                                HardDiskDrive *assignedHDD ) {
    RAM = assignedRAM;
    HDD = assignedHDD;
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

}

