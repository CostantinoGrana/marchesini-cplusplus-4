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
    
    // Stream operator (friend function)
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
};

#endif // RATIONAL_H
