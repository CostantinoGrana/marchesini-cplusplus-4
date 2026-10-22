#include "rational.h"
#include <cstdlib>    // for std::abs
#include <stdexcept>

// Constructor
Rational::Rational(int num, int den) : numerator_(num), denominator_(den) {
    if (denominator_ == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    normalize();
}

void Rational::normalize() {
    // Handle sign: move negative sign to numerator
    if (denominator_ < 0) {
        numerator_ = -numerator_;
        denominator_ = -denominator_;
    }
    
    // Reduce to lowest terms using GCD
    int gcd = std::gcd(std::abs(numerator_), std::abs(denominator_));
    numerator_ /= gcd;
    denominator_ /= gcd;
}

// Output stream operator
std::ostream& operator<<(std::ostream& os, const Rational& r) {
    if (r.denominator_ == 1) {
        os << r.numerator_;
    } else {
        os << r.numerator_ << "/" << r.denominator_;
    }
    return os;
}
