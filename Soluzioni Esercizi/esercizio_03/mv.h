#ifndef MV_H
#define MV_H

#include <numeric>
#include <iterator>
#include <algorithm>
#include <type_traits>

// Helper to check if a type is iterable
template<typename T, typename = void>
struct is_iterable : std::false_type {};

template<typename T>
struct is_iterable<T, std::void_t<
    decltype(std::declval<T>().begin()),
    decltype(std::declval<T>().end())
>> : std::true_type {};

// Same check as is_iterable, written as a C++20 concept
template<typename T>
concept Iterable = requires(T t) {
    t.begin();
    t.end();
};

// Mean01: Basic Loop Implementation (only for iterable containers)
template<typename Container>
typename std::enable_if<is_iterable<Container>::value, double>::type
Mean01(const Container &c) {
    if (c.empty()) { 
        return 0.0;
    }
    double sum = 0.0;
    for (const auto& val : c) {
        sum += val;
    }
    return sum / std::distance(c.begin(), c.end());
}

// Mean01Concept: same as Mean01, constrained with the Iterable concept
template<Iterable Container>
double Mean01Concept(const Container &c) {
    if (c.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (const auto& val : c) {
        sum += val;
    }
    return sum / std::distance(c.begin(), c.end());
}

// Mean02: std::accumulate
template<typename Container>
double Mean02(const Container &c) {
    if (c.empty()) { 
        return 0.0;
    }
    double sum = std::accumulate(c.begin(), c.end(), 0.0);
    return sum / std::distance(c.begin(), c.end());
}

// Mean03: Iterator-based Loop
template<typename Container>
double Mean03(const Container &c) {
    if (c.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (auto it = c.begin(); it != c.end(); ++it) {
        sum += *it;
    }
    return sum / std::distance(c.begin(), c.end());
}

// int foo(auto a){} 

// Mean04: std::for_each with Lambda
template<typename Container>
double Mean04(const Container &c) {
    if (c.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    std::for_each(c.begin(), c.end(), [&sum](const auto& val) { sum += val; });
    return sum / std::distance(c.begin(), c.end());
}

// Mean05: std::reduce (C++17)
template<typename Container>
double Mean05(const Container &c) {
    if (c.empty()) { 
        return 0.0;
    }
    double sum = std::reduce(c.begin(), c.end(), 0.0);
    return sum / std::distance(c.begin(), c.end());
}

// Mean06: Using size() method (requires container with size())
template<typename Container>
double Mean06(const Container &c) {
    if (c.empty()) { 
        return 0.0;
    }
    double sum = std::accumulate(c.begin(), c.end(), 0.0);
    return sum / c.size();
}

// Mean07: Iterator - Two passes (distance + accumulate)
template<typename Iterator>
double Mean07(Iterator begin, Iterator end) {
    if (begin == end) {
        return 0.0;
    }
    double sum = std::accumulate(begin, end, 0.0);
    size_t count = std::distance(begin, end);
    return sum / count;
}

// Mean08: Iterator - Single pass
template<typename Iterator>
double Mean08(Iterator begin, Iterator end) {
    if (begin == end) {
        return 0.0;
    }
    double sum = 0.0;
    size_t count = 0;
    for (auto it = begin; it != end; ++it) {
        sum += *it;
        ++count;
    }
    return sum / count;
}

// Mean09: Iterator - Using std::for_each
template<typename Iterator>
double Mean09(Iterator begin, Iterator end) {
    if (begin == end) {
        return 0.0;
    }
    double sum = 0.0;
    size_t count = 0;
    std::for_each(begin, end, [&sum, &count](const auto& val) {
        sum += val;
        ++count;
    });
    return sum / count;
}

// Mean10: Iterator - Using std::reduce (C++17)
template<typename Iterator>
double Mean10(Iterator begin, Iterator end) {
    if (begin == end) {
        return 0.0;
    }
    double sum = std::reduce(begin, end, 0.0);
    size_t count = std::distance(begin, end);
    return sum / count;
}

// Variance01: Two-Pass with Loop
template<typename Container>
double Variance01(const Container &c) {
    if (c.empty()) { 
        return 0.0;
    }
    double mean = Mean01(c);
    double variance = 0.0;
    for (const auto& val : c) {
        variance += (val - mean) * (val - mean);
    }
    return variance / std::distance(c.begin(), c.end());
}

// Variance02: Using std::accumulate
template<typename Container>
double Variance02(const Container &c) {
    if (c.empty()) {
        return 0.0;
    }
    double mean = Mean01(c);
    double variance = std::accumulate(c.begin(), c.end(), 0.0,
        [mean](double acc, const auto& val) {
            return acc + (val - mean) * (val - mean);
        });
    return variance / std::distance(c.begin(), c.end());
}

// Variance03: Single-Pass Algorithm
template<typename Container>
double Variance03(const Container &c) {
    if (c.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    double sum_sq = 0.0;
    for (const auto& val : c) {
        sum += val;
        sum_sq += val * val;
    }
    size_t count = std::distance(c.begin(), c.end());
    double mean = sum / count;
    return (sum_sq / count) - (mean * mean);
}

// Variance04: Using std::transform_reduce (C++17)
template<typename Container>
double Variance04(const Container &c) {
    if (c.empty()) {
        return 0.0;
    }
    double mean = Mean02(c);
    double variance = std::transform_reduce(
        c.begin(), c.end(),
        0.0,
        std::plus<>(),
        [mean](const auto& val) { return (val - mean) * (val - mean); }
    );
    return variance / std::distance(c.begin(), c.end());
}

// Variance05: Iterator - Two-Pass
template<typename Iterator>
double Variance05(Iterator begin, Iterator end) {
    if (begin == end) return 0.0;
    
    double mean = Mean08(begin, end);
    double variance = 0.0;
    size_t count = 0;
    
    for (auto it = begin; it != end; ++it) {
        variance += (*it - mean) * (*it - mean);
        ++count;
    }
    
    return variance / count;
}

// Variance06: Iterator - Using std::accumulate
template<typename Iterator>
double Variance06(Iterator begin, Iterator end) {
    if (begin == end) return 0.0;
    
    double mean = Mean08(begin, end);
    double variance = std::accumulate(begin, end, 0.0,
        [mean](double acc, const auto& val) {
            return acc + (val - mean) * (val - mean);
        });
    
    size_t count = std::distance(begin, end);
    return variance / count;
}

// Variance07: Iterator - Single-Pass Algorithm
template<typename Iterator>
double Variance07(Iterator begin, Iterator end) {
    if (begin == end) return 0.0;
    
    double sum = 0.0;
    double sum_sq = 0.0;
    size_t count = 0;
    
    for (auto it = begin; it != end; ++it) {
        sum += *it;
        sum_sq += (*it) * (*it);
        ++count;
    }
    
    double mean = sum / count;
    return (sum_sq / count) - (mean * mean);
}

// Variance08: Iterator - Using std::transform_reduce (C++17)
template<typename Iterator>
double Variance08(Iterator begin, Iterator end) {
    if (begin == end) return 0.0;
    
    double mean = Mean08(begin, end);
    double variance = std::transform_reduce(
        begin, end,
        0.0,
        std::plus<>(),
        [mean](const auto& val) { return (val - mean) * (val - mean); }
    );
    
    size_t count = std::distance(begin, end);
    return variance / count;
}

#endif // MV_H
