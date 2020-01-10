#include <iostream>
#include "OperationSystem.h"

int main() {

    OperationSystem OS{};

    OS.getCPU()->run( 30 );

    return 0;
}
