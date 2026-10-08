#include "ribalta.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>

template<typename Container>
void printContainer(const Container& c) {
    for (const auto& elem : c) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Esercizio 5: Ribalta - Container-Agnostic Implementations" << std::endl;
    std::cout << "=========================================================\n" << std::endl;
    
    // Test with vector
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "=== Testing with std::vector<int> ===" << std::endl;
    
    std::vector<int> v1 = vec;
    std::cout << "Ribalta01 (std::reverse):" << std::endl;
    std::cout << "Before: ";
    printContainer(v1);
    Ribalta01(v1);
    std::cout << "After:  ";
    printContainer(v1);
    std::cout << std::endl;
    
    std::vector<int> v2 = vec;
    std::cout << "Ribalta02 (Manual iterators):" << std::endl;
    std::cout << "Before: ";
    printContainer(v2);
    Ribalta02(v2);
    std::cout << "After:  ";
    printContainer(v2);
    std::cout << std::endl;
    
    std::vector<int> v3 = vec;
    std::cout << "Ribalta03 (swap_ranges + rbegin):" << std::endl;
    std::cout << "Before: ";
    printContainer(v3);
    Ribalta03(v3);
    std::cout << "After:  ";
    printContainer(v3);
    std::cout << std::endl;
    
    std::vector<int> v6 = vec;
    std::cout << "Ribalta06 (Manual with advance):" << std::endl;
    std::cout << "Before: ";
    printContainer(v6);
    Ribalta06(v6);
    std::cout << "After:  ";
    printContainer(v6);
    std::cout << std::endl;
    
    // Test with list
    std::list<std::string> lst = {"a", "b", "c", "d"};
    std::cout << "=== Testing with std::list<string> ===" << std::endl;
    
    std::list<std::string> l1 = lst;
    std::cout << "Ribalta01 (std::reverse):" << std::endl;
    std::cout << "Before: ";
    printContainer(l1);
    Ribalta01(l1);
    std::cout << "After:  ";
    printContainer(l1);
    std::cout << std::endl;
    
    std::list<std::string> l2 = lst;
    std::cout << "Ribalta02 (Manual iterators):" << std::endl;
    std::cout << "Before: ";
    printContainer(l2);
    Ribalta02(l2);
    std::cout << "After:  ";
    printContainer(l2);
    std::cout << std::endl;
    
    // Test with deque
    std::deque<double> deq = {1.1, 2.2, 3.3, 4.4};
    std::cout << "=== Testing with std::deque<double> ===" << std::endl;
    
    std::deque<double> d1 = deq;
    std::cout << "Ribalta01 (std::reverse):" << std::endl;
    std::cout << "Before: ";
    printContainer(d1);
    Ribalta01(d1);
    std::cout << "After:  ";
    printContainer(d1);
    std::cout << std::endl;
    
    // Test iterator-based versions
    std::cout << "=== Testing Iterator-Based Versions ===" << std::endl;
    
    std::vector<int> v7 = vec;
    std::cout << "Ribalta07 (Iterator - std::reverse):" << std::endl;
    std::cout << "Before: ";
    printContainer(v7);
    Ribalta07(v7.begin(), v7.end());
    std::cout << "After:  ";
    printContainer(v7);
    std::cout << std::endl;
    
    std::vector<int> v8 = vec;
    std::cout << "Ribalta08 (Iterator - Manual swap):" << std::endl;
    std::cout << "Before: ";
    printContainer(v8);
    Ribalta08(v8.begin(), v8.end());
    std::cout << "After:  ";
    printContainer(v8);
    std::cout << std::endl;
    
    // Test with strings using Ribalta01
    std::vector<std::string> words = {"hello", "world", "c++", "programming"};
    std::cout << "\n=== Testing with strings (Ribalta01) ===" << std::endl;
    std::cout << "Before: ";
    printContainer(words);
    Ribalta01(words);
    std::cout << "After:  ";
    printContainer(words);
    
    return 0;
}
