//
// Created by Pavel on 25/12/2019.
//

#ifndef VIRTUALMEMORY_HARDDISKDRIVE_H
#define VIRTUALMEMORY_HARDDISKDRIVE_H


#include "globals.h"

class HardDiskDrive {
public:
    HardDiskDrive();
    virtual ~HardDiskDrive();

    void setByte( char data, addressType address );
    char getByte( addressType address );
    void delByte( addressType address );
    void print();

private:
    char data[ HDDSize ];
    bool bitmap[ HDDSize ];
};


#endif //VIRTUALMEMORY_HARDDISKDRIVE_H
