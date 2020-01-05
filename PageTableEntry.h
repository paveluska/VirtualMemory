//
// Created by Pavel on 26/12/2019.
//

#ifndef VIRTUALMEMORY_PAGETABLEENTRY_H
#define VIRTUALMEMORY_PAGETABLEENTRY_H

class PageTableEntry {
public:
    PageTableEntry();

    virtual ~PageTableEntry();

private:
    bool isCached;
    bool isModified;
    bool isReferenced;
    bool isProtected;
    bool isPresent;
    unsigned int pageFrameNumber;
};


#endif //VIRTUALMEMORY_PAGETABLEENTRY_H
