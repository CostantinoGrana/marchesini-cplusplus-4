#include "farfallino.h"
#include <iostream>

int main() {
    std::string test1 = "ciao";
    std::string test2 = "Prova";
    std::string test3 = "Hello World";
    
    std::cout << "Test: \"" << test1 << "\"" << std::endl;
    std::cout << "CodificaFarfallino01: " << CodificaFarfallino01(test1) << std::endl;
    std::cout << "CodificaFarfallino02: " << CodificaFarfallino02(test1) << std::endl;
    std::cout << "CodificaFarfallino03: " << CodificaFarfallino03(test1) << std::endl;
    std::cout << "CodificaFarfallino04: " << CodificaFarfallino04(test1) << std::endl;
    std::cout << "CodificaFarfallino05: " << CodificaFarfallino05(test1) << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Test: \"" << test2 << "\"" << std::endl;
    std::cout << "CodificaFarfallino01: " << CodificaFarfallino01(test2) << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Test: \"" << test3 << "\"" << std::endl;
    std::cout << "CodificaFarfallino01: " << CodificaFarfallino01(test3) << std::endl;
    
    return 0;
}
