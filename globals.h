//
// Created by Pavel on 25/12/2019.
//

#ifndef VIRTUALMEMORY_GLOBALS_H
#define VIRTUALMEMORY_GLOBALS_H

#include <cstdint>

typedef uint16_t addressType;     // 16 bit address
const unsigned int addressTypeMax = UINT16_MAX;
const unsigned int RAMSize{ 1024 };    // ram size
const unsigned int HDDSize{ 8192 };    // hdd size
const unsigned int pageSize{ 128 };    // page size
const unsigned int pageTableSize{ addressTypeMax/pageSize };    // page table size
const unsigned int frameTableSize{ HDDSize/pageSize };    // page table size


#endif //VIRTUALMEMORY_GLOBALS_H
