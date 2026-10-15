#include "hexstring.h"
#include <iostream>
#include <iomanip>

void print_vector(const std::vector<int>& v) {
    std::cout << "[ ";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "0x" << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << v[i];
        if (i < v.size() - 1) std::cout << ", ";
    }
    std::cout << " ]" << std::dec << std::endl;
}

int main() {

    // std::string s = "prova";
    // std::cout << std::setfill('0') << std::left << std::setw(10) << "\"" + s;

    std::string test1 = "12AB34CD56EF7890";
    std::string test2 = "12ab34cd56ef7890";
    std::string test3 = "35AF";
    std::string test4 = "0A0a0B0bcCdD";
    std::string test5 = "";
    
    std::cout << "Test: \"" << test1 << "\"" << std::endl;
    std::cout << "HexStringToValues01: ";
    print_vector(HexStringToValues01(test1));
    std::cout << "HexStringToValues02: ";
    print_vector(HexStringToValues02(test1));
    std::cout << "HexStringToValues03: ";
    print_vector(HexStringToValues03(test1));
    std::cout << "HexStringToValues04: ";
    print_vector(HexStringToValues04(test1));
    
    std::cout << std::endl;
    
    std::cout << "Test: \"" << test2 << "\"" << std::endl;
    std::cout << "HexStringToValues01: ";
    print_vector(HexStringToValues01(test2));
    
    std::cout << std::endl;
    
    std::cout << "Test: \"" << test3 << "\"" << std::endl;
    std::cout << "HexStringToValues01: ";
    print_vector(HexStringToValues01(test3));
    
    std::cout << std::endl;
    
    std::cout << "Test: \"" << test4 << "\"" << std::endl;
    std::cout << "HexStringToValues01: ";
    print_vector(HexStringToValues01(test4));
    
    std::cout << std::endl;
    
    std::cout << "Test: \"" << test5 << "\" (empty)" << std::endl;
    std::cout << "HexStringToValues01: ";
    print_vector(HexStringToValues01(test5));
    
    return 0;
}
