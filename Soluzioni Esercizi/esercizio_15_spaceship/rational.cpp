#include "rational.h"
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

// Addition operator (implemented in terms of +=)
Rational Rational::operator+(const Rational& other) const {
    Rational result(*this);  // Copy constructor
    result += other;         // Use += to do the actual work
    return result;
}

// Addition assignment operator
Rational& Rational::operator+=(const Rational& other) {
    // *this = *this + other;
    numerator_ = numerator_ * other.denominator_ + other.numerator_ * denominator_;
    denominator_ = denominator_ * other.denominator_;
    normalize();
    return *this;
}

// Subtraction operator (implemented in terms of -=)
Rational Rational::operator-(const Rational& other) const {
    Rational result(*this);
    result -= other;
    return result;
}

// Subtraction assignment operator
Rational& Rational::operator-=(const Rational& other) {
    numerator_ = numerator_ * other.denominator_ - other.numerator_ * denominator_;
    denominator_ = denominator_ * other.denominator_;
    normalize();
    return *this;
}

// Multiplication operator (implemented in terms of *=)
Rational Rational::operator*(const Rational& other) const {
    Rational result(*this);
    result *= other;
    return result;
}

// Multiplication assignment operator
Rational& Rational::operator*=(const Rational& other) {
    numerator_ *= other.numerator_;
    denominator_ *= other.denominator_;
    normalize();
    return *this;
}

// Division operator (implemented in terms of /=)
Rational Rational::operator/(const Rational& other) const {
    Rational result(*this);
    result /= other;  // This will handle the division by zero check
    return result;
}

// Division assignment operator
Rational& Rational::operator/=(const Rational& other) {
    if (other.numerator_ == 0) {
        throw std::invalid_argument("Division by zero");
    }
    numerator_ *= other.denominator_;
    denominator_ *= other.numerator_;
    normalize();
    return *this;
}

// Unary minus (negation)
Rational Rational::operator-() const {
    return Rational(-numerator_, denominator_);
}

// Unary plus (identity)
Rational Rational::operator+() const {
    return *this;
}

// Three-way comparison (C++20)
// Returns std::strong_ordering::less, ::equal or ::greater.
std::strong_ordering Rational::operator<=>(const Rational& other) const {
    // a/b <=> c/d  =>  a*d <=> c*b  (valid because denominators are always > 0)
    // long long avoids overflow of the cross products
    return static_cast<long long>(numerator_) * other.denominator_
       <=> static_cast<long long>(other.numerator_) * denominator_;
}

//Output stream operator
std::ostream& operator<<(std::ostream& os, const Rational& r) {
    if (r.denominator_ == 1) {
        os << r.numerator_;
    } else {
        os << r.numerator_ << "/" << r.denominator_;
    }
    return os;
}
//Output stream operator non-friend
// std::ostream& operator<<(std::ostream& os, const Rational& r) {
//     if (r.getDenominator() == 1) {
//         os << r.getNumerator();
//     } else {
//         os << r.getNumerator() << "/" << r.getDenominator();
//     }
//     return os;
// }

// Input stream operator
std::istream& operator>>(std::istream& is, Rational& r) {
    int num, den = 1;
    
    // Read the numerator
    if (!(is >> num)) {
        return is;
    }
    
    char next_char;
    if (is >> next_char) {  // This automatically skips whitespace
        if (next_char == '/') {
            if (!(is >> den)) {
                is.setstate(std::ios::failbit);
                return is;
            }
        } else {
            is.putback(next_char);
        }
    } else {
        // Only clear EOF flag, preserve other error states
        // is.clear();
        
        const auto stream_state = is.rdstate();
        const bool state_eofbit = (stream_state & std::ios::eofbit) != 0;
        const bool state_failbit = (stream_state & std::ios::failbit) != 0;
        const bool state_badbit = (stream_state & std::ios::badbit) != 0;
        
        if (is.eof() && !is.bad()) {
            is.clear(std::ios::eofbit);
        }
    }
    
    r = Rational(num, den);
    return is;
}

/* ALTERNATIVE CHARACTER-BY-CHARACTER VERSION:
std::istream& operator>>(std::istream& is, Rational& r) {
    char ch;
    int num = 0, den = 1;
    bool negative = false;
    bool found_slash = false;
    bool reading_num = true;
    
    // Skip leading whitespace
    while (is.get(ch) && std::isspace(ch)) {
        // continue skipping
    }
    
    if (!is) {
        return is; // EOF or error
    }
    
    // Check for negative sign
    if (ch == '-') {
        negative = true;
        if (!is.get(ch)) {
            is.setstate(std::ios::failbit);
            return is;
        }
    } else if (ch == '+') {
        if (!is.get(ch)) {
            is.setstate(std::ios::failbit);
            return is;
        }
    }
    
    // Read numerator
    if (!std::isdigit(ch)) {
        is.setstate(std::ios::failbit);
        return is;
    }
    
    // Build numerator digit by digit
    num = ch - '0';
    while (is.get(ch) && std::isdigit(ch)) {
        num = num * 10 + (ch - '0');
    }
    
    if (!is) {
        // EOF reached, that's OK - just a numerator
        is.clear();
        r = Rational(negative ? -num : num, 1);
        return is;
    }
    
    // Skip whitespace before potential '/'
    while (std::isspace(ch) && is.get(ch)) {
        // continue skipping
    }
    
    if (!is) {
        // EOF after whitespace, that's OK
        is.clear();
        r = Rational(negative ? -num : num, 1);
        return is;
    }
    
    // Check for '/' 
    if (ch == '/') {
        found_slash = true;
        
        // Skip whitespace after '/'
        while (is.get(ch) && std::isspace(ch)) {
            // continue skipping
        }
        
        if (!is || !std::isdigit(ch)) {
            is.setstate(std::ios::failbit);
            return is;
        }
        
        // Build denominator digit by digit
        den = ch - '0';
        while (is.get(ch) && std::isdigit(ch)) {
            den = den * 10 + (ch - '0');
        }
        
        // Put back the non-digit character for next read
        if (is) {
            is.putback(ch);
        } else {
            // EOF is OK
            is.clear();
        }
    } else {
        // Not a '/', put character back for next read
        is.putback(ch);
    }
    
    r = Rational(negative ? -num : num, den);
    return is;
}
*/

// Hash function implementation
std::size_t Rational::Hash::operator()(const Rational& r) const {
    // Combine hash of numerator and denominator
    std::size_t h1 = std::hash<int>{}(r.numerator_);
    std::size_t h2 = std::hash<int>{}(r.denominator_);
    return h1 ^ (h2 << 1);
}

// Non-member arithmetic operators for int on left side
Rational operator+(int lhs, const Rational& rhs) {
    return rhs + lhs;  // Addition is commutative: a + b = b + a
}

Rational operator-(int lhs, const Rational& rhs) {
    return Rational(lhs) - rhs;
}

Rational operator*(int lhs, const Rational& rhs) {
    return rhs * lhs;  // Multiplication is commutative: a * b = b * a
}

Rational operator/(int lhs, const Rational& rhs) {
    return Rational(lhs) / rhs;
}