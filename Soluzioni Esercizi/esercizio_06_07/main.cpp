#include "nodup.h"
#include <iostream>
#include <vector>
#include <string>

template<typename T>
void printVector(const std::vector<T>& v) {
    std::cout << "{";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i < v.size() - 1) std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}

int main() {
    std::vector<int> v_in = {4, 1, 1, 4, 7, 9, 7};
    
    std::cout << "Esercizio 6: nodup - Effective Implementations" << std::endl;
    std::cout << "===============================================\n" << std::endl;
    
    std::cout << "Input: ";
    printVector(v_in);
    std::cout << std::endl;
    
    // Test Nodup01 - O(n) average
    std::cout << "Nodup01 (unordered_set with find) - O(n):" << std::endl;
    std::cout << "Output: ";
    printVector(Nodup01(v_in));
    std::cout << std::endl;
    
    // Test Nodup02 - O(n) average
    std::cout << "Nodup02 (unordered_set with insert().second) - O(n):" << std::endl;
    std::cout << "Output: ";
    printVector(Nodup02(v_in));
    std::cout << std::endl;
    
    // Test Nodup03 - O(n log n)
    std::cout << "Nodup03 (set - sorted output) - O(n log n):" << std::endl;
    std::cout << "Output: ";
    printVector(Nodup03(v_in));
    std::cout << std::endl;
    
    // Test Nodup04 - O(n log n)
    std::cout << "Nodup04 (sort + unique) - O(n log n):" << std::endl;
    std::cout << "Output: ";
    printVector(Nodup04(v_in));
    std::cout << std::endl;
    
    // Test Nodup05 - O(n²)
    std::cout << "Nodup05 (Manual nested loop) - O(n²):" << std::endl;
    std::cout << "Output: ";
    printVector(Nodup05(v_in));
    std::cout << std::endl;
    
    // Test Nodup06 - O(n²)
    std::cout << "Nodup06 (std::find) - O(n²):" << std::endl;
    std::cout << "Output: ";
    printVector(Nodup06(v_in));
    std::cout << std::endl;

    // Test Nodup07 - O(n log n), in-place
    std::cout << "Nodup07 (in-place nodup: sort + swap + erase) - O(n log n):" << std::endl;
    std::cout << "Output: ";
    printVector(Nodup07(v_in));
    std::cout << std::endl;
    
    // Test with strings
    std::vector<std::string> words = {"hello", "world", "hello", "c++", "world", "programming"};
    std::cout << "=== Testing with strings (Nodup01) ===" << std::endl;
    std::cout << "Input:  ";
    printVector(words);
    std::cout << "Output: ";
    printVector(Nodup01(words));

    std::cout << "\n=== Testing with strings (in-place nodup) ===" << std::endl;
    words.erase(nodup(words.begin(), words.end()), words.end());
    std::cout << "Output: ";
    printVector(words);

    return 0;
}
