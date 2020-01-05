//
// Created by Pavel on 25/12/2019.
//

#include "VirtualMemoryPage.h"

unsigned int nextFrameNumber{};

VirtualMemoryPage::VirtualMemoryPage()
: isReferenced{ 0 }, isProtected{ 0 }, isPresent{ 0 }, isModified{ 0 }, isCached{ 0 }, frameNumber{ nextFrameNumber++ } {

}

VirtualMemoryPage::~VirtualMemoryPage() {

}

bool VirtualMemoryPage::getCached() const {
    return isCached;
}

void VirtualMemoryPage::setCached(bool isCached) {
    VirtualMemoryPage::isCached = isCached;
}

bool VirtualMemoryPage::getModified() const {
    return isModified;
}

void VirtualMemoryPage::setModified(bool isModified) {
    VirtualMemoryPage::isModified = isModified;
}

bool VirtualMemoryPage::getReferenced() const {
    return isReferenced;
}

void VirtualMemoryPage::setReferenced(bool isReferenced) {
    VirtualMemoryPage::isReferenced = isReferenced;
}

bool VirtualMemoryPage::getProtected() const {
    return isProtected;
}

void VirtualMemoryPage::setProtected(bool isProtected) {
    VirtualMemoryPage::isProtected = isProtected;
}

bool VirtualMemoryPage::getPresent() const {
    return isPresent;
}

void VirtualMemoryPage::setPresent(bool isPresent) {
    VirtualMemoryPage::isPresent = isPresent;
}

unsigned int VirtualMemoryPage::getFrameNumber() const {
    return frameNumber;
}

void VirtualMemoryPage::setFrameNumber(unsigned int frameNumber) {
    VirtualMemoryPage::frameNumber = frameNumber;
}
