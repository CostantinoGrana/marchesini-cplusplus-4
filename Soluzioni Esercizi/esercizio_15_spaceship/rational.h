#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <numeric>  // for std::gcd
#include <compare>  // for std::strong_ordering (C++20)

// operator<=> (three-way comparison, "spaceship") requires C++20:
// compile with -std=c++20 (g++/clang++) or /std:c++20 (MSVC)
#if !defined(__cpp_impl_three_way_comparison)
#error "This version of Rational requires C++20 (operator<=>)"
#endif

class Rational {
private:
    int numerator_;
    int denominator_;
    
    void normalize();

public:
    Rational(int num = 0, int den = 1);
    
    int getNumerator() const { return numerator_; }
    int getDenominator() const { return denominator_; }

    Rational operator+(const Rational& other) const;
    Rational& operator+=(const Rational& other);
    Rational operator-(const Rational& other) const;
    Rational& operator-=(const Rational& other);
    Rational operator*(const Rational& other) const;
    Rational& operator*=(const Rational& other);
    Rational operator/(const Rational& other) const;
    Rational& operator/=(const Rational& other);
    
    Rational operator-() const;  // negation
    Rational operator+() const;  // identity
    
    // C++20: these two replace all six comparison operators.
    // - From operator== the compiler rewrites a != b as !(a == b)
    // - From operator<=> the compiler rewrites a < b as (a <=> b) < 0,
    //   and similarly for <=, >, >=
    // Rewritten expressions also try the reversed operands, so 3 < r becomes
    // 0 < (r <=> 3) and 3 == r becomes r == 3: no int-on-the-left overloads needed.
    //
    // Defaulted == compares members one by one (numerator_, then denominator_):
    // correct only because normalize() keeps every Rational in canonical form.
    bool operator==(const Rational& other) const = default;

    // Must NOT be defaulted: memberwise comparison would say 1/3 > 1/2
    // (same numerator, then 3 > 2). We need a/b <=> c/d  ==>  a*d <=> c*b.
    std::strong_ordering operator<=>(const Rational& other) const;

    // Stream operators (friend functions)
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);
    
    // Hash function for unordered_map support
    struct Hash {
        std::size_t operator()(const Rational& r) const;
    };
};

// Non-member arithmetic operators for int operands
Rational operator+(int lhs, const Rational& rhs);
Rational operator-(int lhs, const Rational& rhs);
Rational operator*(int lhs, const Rational& rhs);
Rational operator/(int lhs, const Rational& rhs);

#endif // RATIONAL_H
