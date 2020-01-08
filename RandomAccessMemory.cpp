//
// Created by Pavel on 25/12/2019.
//

#include "RandomAccessMemory.h"

#include <iostream>
#include <iomanip>

using std::cout;
using std::cerr;
using std::endl;
using std::setw;

RandomAccessMemory::RandomAccessMemory(): data{}, bitmap{} {
    for ( int i{}; i < RAMSize; i++ ) {
        data[ i ] = '0';
        bitmap[ i ] = 0;
    }
}

RandomAccessMemory::~RandomAccessMemory() {

}

void RandomAccessMemory::print() {
    int wide{4};
    cout << setw(wide) << 1 << ": ";
    for (int i{}; i < RAMSize; i++) {
        cout << data[i];
        // 10 percent of the ram per line gets printed
        if ( (i+1) %(RAMSize/10) == 0 ) {
            cout << endl << setw(wide) << i+1 << ": ";
            // a dot dividing a block of 8 byte for visibility
        } else if((i+1)%pageSize == 0) {
            cout << ":nextPage:";
        } else if((i+1)%10 == 0) {
            cout << ".";
        }
    }
    cout << endl;
}

void RandomAccessMemory::clear() {
    for ( int i{}; i < RAMSize; i++ ) {
        data[ i ] = '0';
        bitmap[ i ] = 0;
    }
}

bool RandomAccessMemory::getBit(unsigned int index ) {
    if ( index < RAMSize )
        return bitmap[ index ];
    cerr << "asking for out of bound status bit from ram, returning true!" << endl;
    return 1;
}

void RandomAccessMemory::setBit( addressType address, bool data ) {
    bitmap[ address ] = data;
}

void RandomAccessMemory::setData( addressType address, char data ) {
    this->data[ (int)address ] = data;
}

char RandomAccessMemory::getData( addressType address ) {
    return data[ address ];
}
