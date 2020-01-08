//
// Created by Pavel on 25/12/2019.
//

#include "HardDiskDrive.h"

#include <iostream>
#include <iomanip>

using std::cout;
using std::cerr;
using std::setw;
using std::endl;

HardDiskDrive::HardDiskDrive() : data{}, bitmap{} {
    for ( int i{}; i < HDDSize; i++ ) {
        data[ i ] = '0';
        bitmap[ i ] = 0;
    }
}

HardDiskDrive::~HardDiskDrive() {

}

void HardDiskDrive::setByte( char inData, addressType address) {
    data[ (int)address ] = inData;
    bitmap[ (int)address ] = 1;
}

void HardDiskDrive::delByte( addressType address) {
    data[ (int)address ] = '0';
    bitmap[ (int)address ] = 0;
}

void HardDiskDrive::print() {
    int wide{4};
    cout << setw(wide) << 1 << ": ";
    for (int i{}; i < HDDSize; i++) {
        cout << data[i];
        // 10 percent of the ram per line gets printed
        if ( (i+1) %(HDDSize/10) == 0 ) {
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

char HardDiskDrive::getByte(addressType address) {
    if ( address >= HDDSize )
        cerr << "reading a out of bounds byte from hdd!" << endl;
    return data[ (int)address ];
}
