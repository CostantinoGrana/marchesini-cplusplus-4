#include "ribalta.h"
#include <iostream>
#include <vector>
#include <string>

template<typename T>
void printVector(const std::vector<T>& v) {
    for (const auto& elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = {1, 7, 5, 3};
    
    std::cout << "Esercizio 4: Ribalta - Multiple Implementations" << std::endl;
    std::cout << "=================================================\n" << std::endl;
    
    // Test Ribalta01
    std::vector<int> v1 = numbers;
    std::cout << "Ribalta01 (Manual Loop - Index):" << std::endl;
    std::cout << "Before: ";
    printVector(v1);
    Ribalta01(v1);
    std::cout << "After:  ";
    printVector(v1);
    std::cout << std::endl;
    
    // Test Ribalta02
    std::vector<int> v2 = numbers;
    std::cout << "Ribalta02 (Manual Loop - Iterators):" << std::endl;
    std::cout << "Before: ";
    printVector(v2);
    Ribalta02(v2);
    std::cout << "After:  ";
    printVector(v2);
    std::cout << std::endl;
    
    // Test Ribalta03
    std::vector<int> v3 = numbers;
    std::cout << "Ribalta03 (std::reverse):" << std::endl;
    std::cout << "Before: ";
    printVector(v3);
    Ribalta03(v3);
    std::cout << "After:  ";
    printVector(v3);
    std::cout << std::endl;
    
    // Test Ribalta04
    std::vector<int> v4 = numbers;
    std::cout << "Ribalta04 (Loop from both ends):" << std::endl;
    std::cout << "Before: ";
    printVector(v4);
    Ribalta04(v4);
    std::cout << "After:  ";
    printVector(v4);
    std::cout << std::endl;
    
    // Test Ribalta05
    std::vector<int> v5 = numbers;
    std::cout << "Ribalta05 (swap_ranges + rbegin):" << std::endl;
    std::cout << "Before: ";
    printVector(v5);
    Ribalta05(v5);
    std::cout << "After:  ";
    printVector(v5);
    std::cout << std::endl;
    
    // Test with strings
    std::vector<std::string> words = {"hello", "world", "c++", "programming"};
    std::cout << "Testing with strings (Ribalta01):" << std::endl;
    std::cout << "Before: ";
    printVector(words);
    Ribalta01(words);
    std::cout << "After:  ";
    printVector(words);
    
    return 0;
}