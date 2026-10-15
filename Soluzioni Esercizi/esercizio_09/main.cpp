#include "translate.h"
#include <iostream>
#include <utility>

int main() {
   
    // std::pair<int, int> p{5, 12};
    // std::pair<int, std::string> p{5, "prova"}; 
   
    // auto p = std::make_pair(5, "prova");

    std::string s1 = "ciao";
    std::string s2 = "ciao";
    std::string s3 = "ciao";
    std::string s4 = "ciao";
    std::string s6 = "ciao";
    
    std::cout << "Original: " << s1 << std::endl;
    
    Translate01(s1, "abdc", "wxzy");
    std::cout << "Translate01: " << s1 << std::endl;
    
    Translate02(s2, "abdc", "wxzy");
    std::cout << "Translate02: " << s2 << std::endl;
    
    Translate03(s3, "abdc", "wxzy");
    std::cout << "Translate03: " << s3 << std::endl;
    
    Translate04(s4, "abdc", "wxzy");
    std::cout << "Translate04: " << s4 << std::endl;

    Translate05(s6, "abdc", "wxzy");
    std::cout << "Translate05: " << s6 << std::endl;
    
    std::cout << std::endl;
    
    // Test with different length strings (should not modify)
    std::string s5 = "test";
    std::cout << "Test (different lengths): " << s5 << std::endl;
    Translate01(s5, "abc", "xy");
    std::cout << "After Translate01: " << s5 << std::endl;
    
    return 0;
}
