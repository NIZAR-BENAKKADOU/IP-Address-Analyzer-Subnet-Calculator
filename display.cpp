#include "display.h"
#include <iostream>
#include <iomanip>

void printSeparator() {
    std::cout << "  +-----------------------------------------+" << std::endl;
}

void printHeader(const std::string& title) {
    std::cout << std::endl;
    std::cout << "  +=========================================+" << std::endl;
    std::cout << "  |  " << std::left << std::setw(39) << title << "|" << std::endl;
    std::cout << "  +=========================================+" << std::endl;
}

void printRow(const std::string& label, const std::string& value) {
    std::cout << "  | " << std::left << std::setw(20) << label << ": " << std::setw(18) << value << "|" << std::endl;
}
