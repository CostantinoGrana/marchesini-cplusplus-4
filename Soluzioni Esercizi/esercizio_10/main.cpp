#include "conta.h"
#include <iostream>

int main() {
    std::string test1 = "  Questa e' una stringa lunga 45 caratteri.  ";
    std::string test2 = "1 2 3 a b c";
    std::string test3 = "! @?$ ciao,prova";
    std::string test4 = "";
    std::string test5 = "   ";
    
    std::cout << "Test: \"" << test1 << "\"" << std::endl;
    std::cout << "Conta01: " << Conta01(test1) << std::endl;
    std::cout << "Conta02: " << Conta02(test1) << std::endl;
    std::cout << "Conta03: " << Conta03(test1) << std::endl;
    std::cout << "Conta04: " << Conta04(test1) << std::endl;
    std::cout << "Conta05 (istream_iterator): " << Conta05(test1) << std::endl;
    std::cout << "ContaBonus: " << ContaBonus(test1) << std::endl;
    std::cout << "Conta06 (regex_iterator): " << Conta06(test1) << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Test: \"" << test2 << "\"" << std::endl;
    std::cout << "Conta01: " << Conta01(test2) << std::endl;
    std::cout << "Conta02: " << Conta02(test2) << std::endl;
    std::cout << "Conta03: " << Conta03(test2) << std::endl;
    std::cout << "Conta04: " << Conta04(test2) << std::endl;
    std::cout << "Conta05: " << Conta05(test2) << std::endl;
    std::cout << "Conta06 (regex_iterator): " << Conta06(test2) << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Test: \"" << test3 << "\"" << std::endl;
    std::cout << "Conta01: " << Conta01(test3) << std::endl;
    std::cout << "Conta02: " << Conta02(test3) << std::endl;
    std::cout << "Conta03: " << Conta03(test3) << std::endl;
    std::cout << "Conta04: " << Conta04(test3) << std::endl;
    std::cout << "Conta05: " << Conta05(test3) << std::endl;
    std::cout << "Conta06 (regex_iterator): " << Conta06(test3) << std::endl;

    std::cout << std::endl;
    
    std::cout << "Test: \"" << test4 << "\" (empty)" << std::endl;
    std::cout << "Conta01: " << Conta01(test4) << std::endl;
    std::cout << "Conta02: " << Conta02(test4) << std::endl;
    std::cout << "Conta03: " << Conta03(test4) << std::endl;
    std::cout << "Conta04: " << Conta04(test4) << std::endl;
    std::cout << "Conta05: " << Conta05(test4) << std::endl;
    std::cout << "Conta06 (regex_iterator): " << Conta06(test4) << std::endl;

    std::cout << std::endl;
    
    std::cout << "Test: \"" << test5 << "\" (only spaces)" << std::endl;
    std::cout << "Conta01: " << Conta01(test5) << std::endl;
    std::cout << "Conta02: " << Conta02(test5) << std::endl;
    std::cout << "Conta03: " << Conta03(test5) << std::endl;
    std::cout << "Conta04: " << Conta04(test5) << std::endl;
    std::cout << "Conta05: " << Conta05(test5) << std::endl;
    std::cout << "Conta06 (regex_iterator): " << Conta06(test5) << std::endl;

    return 0;
}
