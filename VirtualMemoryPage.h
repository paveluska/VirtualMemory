//
// Created by Pavel on 25/12/2019.
//

#ifndef VIRTUALMEMORY_VIRTUALMEMORYPAGE_H
#define VIRTUALMEMORY_VIRTUALMEMORYPAGE_H


class VirtualMemoryPage {
public:
    VirtualMemoryPage();
    virtual ~VirtualMemoryPage();

    bool getCached() const;
    void setCached(bool isCached);
    bool getModified() const;
    void setModified(bool isModified);
    bool getReferenced() const;
    void setReferenced(bool isReferenced);
    bool getProtected() const;
    void setProtected(bool isProtected);
    bool getPresent() const;
    void setPresent(bool isPresent);
    unsigned int getFrameNumber() const;
    void setFrameNumber(unsigned int frameNumber);

private:
    bool isCached;  //NN
    bool isModified; // is this page in ram and was modified, so that we need to write back
    bool isReferenced;  // NN
    bool isProtected;   // NN
    bool isPresent; // is the page present in ram
    unsigned int frameNumber;   // page frame number
};


#endif //VIRTUALMEMORY_VIRTUALMEMORYPAGE_H
