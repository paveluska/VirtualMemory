//
// Created by Pavel on 25/12/2019.
//

#ifndef VIRTUALMEMORY_CENTRALPROCESSINGUNIT_H
#define VIRTUALMEMORY_CENTRALPROCESSINGUNIT_H


#include "globals.h"
#include "HardDiskDrive.h"
#include "RandomAccessMemory.h"

class HardDiskDrive;
class RandomAccessMemory;

class CentralProcessingUnit {
public:
    CentralProcessingUnit();
    CentralProcessingUnit( RandomAccessMemory*, HardDiskDrive*);
    virtual ~CentralProcessingUnit();

    void write( char data, addressType address );
    char read( addressType address );
    void switchProcess();
private:
    RandomAccessMemory *RAM;
    HardDiskDrive *HDD;
};


#endif //VIRTUALMEMORY_CENTRALPROCESSINGUNIT_H
