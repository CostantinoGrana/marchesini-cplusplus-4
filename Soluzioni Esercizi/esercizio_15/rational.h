#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <numeric>  // for std::gcd

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
    
    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    bool operator<(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator>=(const Rational& other) const;
    
    // Comparison with integers
    // bool operator==(int value) const;
    // bool operator!=(int value) const;
    // bool operator<(int value) const;
    // bool operator<=(int value) const;
    // bool operator>(int value) const;
    // bool operator>=(int value) const;
    
    // Stream operators (friend functions)
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);
    
    // Hash function for unordered_map support
    struct Hash {
        std::size_t operator()(const Rational& r) const;
    };
};

// Non-member comparison operators for int on left side
bool operator==(int lhs, const Rational& rhs);
bool operator!=(int lhs, const Rational& rhs);
bool operator<(int lhs, const Rational& rhs);
bool operator<=(int lhs, const Rational& rhs);
bool operator>(int lhs, const Rational& rhs);
bool operator>=(int lhs, const Rational& rhs);

// Non-member arithmetic operators for int operands
Rational operator+(int lhs, const Rational& rhs);
Rational operator-(int lhs, const Rational& rhs);
Rational operator*(int lhs, const Rational& rhs);
Rational operator/(int lhs, const Rational& rhs);

#endif // RATIONAL_H
