#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "rational.h"

// namespace std {
//     template<>
//     struct hash<Rational> {
//         std::size_t operator()(const Rational& r) const {
//             return Rational::Hash{}(r);
//         }
//     };
// }

int main() {
    // int a = 5;
    // int b = 4; 

    // a += b += 3;
    
    std::cout << "=== Testing Rational Class ===\n\n";
    
    Rational e = Rational();
    e.getDenominator();

    // Test 1: Basic construction and normalization
    std::cout << "Test 1: Construction and Normalization" << std::endl;
    Rational r1(24, -12);  // Should be normalized to -2/1
    Rational r2(6, 9);     // Should be normalized to 2/3
    Rational r3(5);        // Should be 5/1

    Rational r_example_one = Rational(24, -12);
    Rational r_example_two;

    Rational r_braces_init{24, -12};

    // Test exception handling for invalid denominator
    try {
        Rational r4(1, 0);  // Throws an exception
        std::cout << "This line should not be reached!\n";
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

    std::cout << "r1 (24, -12) = " << r1 << " (expected: -2)" << std::endl;
    std::cout << "r2 (6, 9) = " << r2 << " (expected: 2/3)\n";
    std::cout << "r3 (5) = " << r3 << " (expected: 5)\n\n";

    // Test 2: All arithmetic operations
    std::cout << "Test 2: All Arithmetic Operations\n";
    Rational r4(1, 3);
    Rational r5(1, 6);

    // if (std::cin >> r5){
    //     std::cout << r5;
    // }
    
    // Addition
    Rational sum = r4 + r5;
    std::cout << r4 << " + " << r5 << " = " << sum << " (expected: 1/2)\n";
    
    // Subtraction
    Rational diff = r4 - r5;
    std::cout << r4 << " - " << r5 << " = " << diff << " (expected: 1/6)\n";
    
    // Multiplication
    Rational product = r4 * r5;
    std::cout << r4 << " * " << r5 << " = " << product << " (expected: 1/18)\n";
    
    // Division
    Rational quotient = r4 / r5;
    std::cout << r4 << " / " << r5 << " = " << quotient << " (expected: 2)\n\n";
    
    // Test 3: Assignment operators
    std::cout << "Test 3: Assignment Operators\n";
    Rational r6(1, 4);
    Rational r7(1, 4);
    
    std::cout << "Starting with r6 = " << r6 << "\n";
    r6 += r7;
    std::cout << "After += 1/4: r6 = " << r6 << " (expected: 1/2)\n";
    
    r6 -= Rational(1, 4);
    std::cout << "After -= 1/4: r6 = " << r6 << " (expected: 1/4)\n";
    
    r6 *= Rational(4);
    std::cout << "After *= 4: r6 = " << r6 << " (expected: 1)\n";
    
    r6 /= Rational(2);
    std::cout << "After /= 2: r6 = " << r6 << " (expected: 1/2)\n\n";
    
    // Test aritmetics with integers
    { Rational res = r1 + 5; }
    { Rational res = 5 + r1; }


    // Test 4: Unary operators
    std::cout << "Test 4: Unary Operators\n";
    Rational r8(3, 4);
    std::cout << "Original: " << r8 << "\n";
    std::cout << "Negation (-r): " << -r8 << " (expected: -3/4)\n";
    std::cout << "Identity (+r): " << +r8 << " (expected: 3/4)\n\n";
    
    // Test 5: Mixed operations with integers
    std::cout << "Test 5: Mixed Operations with Integers\n";
    Rational r9(1, 2);
    std::cout << "1/2 + 1 = " << r9 + 1 << " (expected: 3/2)\n";
    std::cout << "2 - 1/2 = " << 2 - r9 << " (expected: 3/2)\n";
    std::cout << "1/2 * 3 = " << r9 * 3 << " (expected: 3/2)\n";
    std::cout << "1 / (1/2) = " << 1 / r9 << " (expected: 2)\n\n";
    
    // Test 6: Equality comparison
    std::cout << "Test 6: Equality Comparison\n";
    Rational r10(2, 4);
    Rational r11(1, 2);
    std::cout << "2/4 == 1/2: " << (r10 == r11 ? "true" : "false") << " (expected: true)\n";
    std::cout << "2/4 != 1/2: " << (r10 != r11 ? "true" : "false") << " (expected: false)\n\n";
    
    // Test 7: Comparison with integers
    std::cout << "Test 7: Comparison with Integers\n";
    Rational r12(3, 1);
    std::cout << "3/1 == 3: " << (r12 == 3 ? "true" : "false") << " (expected: true)\n";
    std::cout << "3 == 3/1: " << (3 == r12 ? "true" : "false") << " (expected: true)\n\n";
    
    // Test 8: Relational operators
    std::cout << "Test 8: Relational Operators\n";
    Rational r13(1, 2);
    Rational r14(3, 4);
    std::cout << "1/2 < 3/4: " << (r13 < r14 ? "true" : "false") << " (expected: true)\n";
    std::cout << "1/2 > 3/4: " << (r13 > r14 ? "true" : "false") << " (expected: false)\n";
    std::cout << "1/2 <= 3/4: " << (r13 <= r14 ? "true" : "false") << " (expected: true)\n";
    std::cout << "1/2 >= 3/4: " << (r13 >= r14 ? "true" : "false") << " (expected: false)\n\n";
    
    // Test 9: File I/O
    std::cout << "Test 9: Reading from File\n";
    std::ifstream input("../../Testi Esercizi/rational_numbers.txt");
    if (!input) {
        std::cerr << "Error: Could not open rational_numbers.txt\n";
        return 1;
    }
    
    std::vector<Rational> numbers;
    Rational temp;
    while (input >> temp) {
        numbers.push_back(temp);
    }
    input.close();
    
    std::cout << "Read " << numbers.size() << " numbers from file:\n";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";
    
    // Test 10: unordered_map with Rational as key
    std::cout << "Test 10: Using Rational with unordered_map\n";
    std::unordered_map<Rational, int, Rational::Hash> countMap;
    
    for (const auto& num : numbers) {
        countMap[num]++;
    }
    
    std::cout << "Frequency count of rational numbers:\n";
    for (const auto& [rational, count] : countMap) {
        std::cout << rational << ": " << count << " times\n";
    }
    std::cout << "\n";
    
    const auto& [rational, count] = make_pair(2, 3)

    // Test 11: Complex operations and demonstration
    std::cout << "Test 11: Complex Operations\n";
    Rational r15(1, 2);
    Rational r16(1, 3);
    Rational r17(1, 6);
    Rational result = r15 + r16 + r17;
    std::cout << "1/2 + 1/3 + 1/6 = " << result << " (expected: 1)\n";
    
    // Demonstrate the power of the complete arithmetic operations
    Rational complex_result = (Rational(3, 4) * Rational(8, 9)) / Rational(2, 3) - Rational(1, 2);
    std::cout << "(3/4 * 8/9) / (2/3) - 1/2 = " << complex_result << " (expected: 1/2)\n";
    
    std::cout << "\n=== All Tests Completed ===\n";
    
    return 0;
}
