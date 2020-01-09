#include <iostream>
#include "OperationSystem.h"

int main() {

    OperationSystem OS{};

    OS.getCPU()->run( 10 );

    return 0;
}
