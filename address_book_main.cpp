#include <iostream>
#include <string>
#include "address_book.h"

int main(int argc, char *argv[]) {

    if (argc > 1) {
        std::cout << "Application does not take arguments." << std::endl;
        return -1;
    } // end if argc > 1

    #ifdef DEBUG
    {
        std::cout << "********************\n";
        std::cout << "**   DEBUG MODE   **\n";
    }
    #endif

    std::cout << "********************\n";
    std::cout << "Welcome User!\n";
    std::cout << "This is Micky's Address Book App!\n";
    std::cout << "--------------------\n";
    run_program();
    std::cout << "--------------------\n";
    std::cout << "App terminated\n";
    std::cout << "********************\n";
    return 0;
}
