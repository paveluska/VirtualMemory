//
// Created by Pavel on 25/12/2019.
//

#ifndef VIRTUALMEMORY_RANDOMACCESSMEMORY_H
#define VIRTUALMEMORY_RANDOMACCESSMEMORY_H


#include "globals.h"

class RandomAccessMemory {
public:
    RandomAccessMemory();
    virtual ~RandomAccessMemory();

    void print();
    void clear();

    bool getBit( unsigned int index);
    void setBit( addressType, bool );
    void setData( addressType, char );
private:
    char data[ RAMSize ];
    bool bitmap[ RAMSize ];
};


#endif //VIRTUALMEMORY_RANDOMACCESSMEMORY_H
