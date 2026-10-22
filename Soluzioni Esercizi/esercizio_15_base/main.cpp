#include <iostream>
#include <stdexcept>
#include "rational.h"

int main() {
    std::cout << "=== Testing Rational Class ===\n\n";

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
    std::cout << "r3 (5) = " << r3 << " (expected: 5)\n";
    std::cout << "r_example_one = " << r_example_one << " (expected: -2)\n";
    std::cout << "r_example_two = " << r_example_two << " (expected: 0)\n";
    std::cout << "r_braces_init = " << r_braces_init << " (expected: -2)\n";

    return 0;
}
