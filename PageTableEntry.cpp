//
// Created by Pavel on 26/12/2019.
//

#include "PageTableEntry.h"

unsigned int nextPageFrameNumber{};

PageTableEntry::PageTableEntry()
    : isCached{ false }, isModified{ false }, isPresent{ false }, isProtected{ false }, isReferenced{ false }, pageFrameNumber{ nextPageFrameNumber++ } {

}

PageTableEntry::~PageTableEntry() {

}
