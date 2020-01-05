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
    bool isCached;
    bool isModified;
    bool isReferenced;
    bool isProtected;
    bool isPresent;
    unsigned int frameNumber;
};


#endif //VIRTUALMEMORY_VIRTUALMEMORYPAGE_H
