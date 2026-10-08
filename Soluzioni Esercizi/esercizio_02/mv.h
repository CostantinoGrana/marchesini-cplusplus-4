#ifndef MV_H
#define MV_H

#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <type_traits>

// Esercizio 2: Mean and Variance for vector of any numeric type (Templates)

// Mean01: Basic Loop Implementation (disabled for int)
template<typename T>
double Mean01(const std::vector<T> &v) {
    //static_assert(!std::is_same<T, int>::value, "Mean01 cannot be used with int type");
    if (v.empty()) { 
        return 0.0;
    }
    double sum = 0.0;
    for (const T& val : v) {
        sum += val;
    }
    return sum / v.size();
}

// Mean01_SFINAE: Same as Mean01 but disabled for int using SFINAE
template<typename T>
std::enable_if_t<!std::is_same_v<T, int>, double>
Mean01_SFINAE(const std::vector<T> &v) {
    if (v.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (const T& val : v) {
        sum += val;
    }
    return sum / v.size();
}

// Mean01_SFINAE_Float: Same as Mean01 but enabled only for float and double using SFINAE
template<typename T>
std::enable_if_t<std::is_same_v<T, float> || std::is_same_v<T, double>, double>
Mean01_SFINAE_Float(const std::vector<T> &v) {
    if (v.empty()) { 
        return 0.0;
    }
    double sum = 0.0;
    for (const T& val : v) {
        sum += val;
    }
    return sum / v.size();
}

// Addable: concept satisfied by types that allow T + T
template<typename T>
concept Addable = requires (T a, T b) {
    a + b;
};

// Mean01_Plus: Same as Mean01 but enabled only for Addable types (C++20 concepts)
template<Addable T>
double Mean01_Plus(const std::vector<T> &v) {
    if (v.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (const T& val : v) {
        sum += val;
    }
    return sum / v.size();
}

// Mean02: std::accumulate
template<typename T>
double Mean02(const std::vector<T> &v) {
    if (v.empty()) { 
        return 0.0;
    }
    double sum = std::accumulate(v.begin(), v.end(), 0.0);
    return sum / v.size();
}

// Mean03: Iterator-based Loop
template<typename T>
double Mean03(const std::vector<T> &v) {
    if (v.empty()) return 0.0;
    double sum = 0.0;
    for (auto it = v.begin(); it != v.end(); ++it) {
        sum += *it;
    }
    return sum / v.size();
}

// Mean04: std::for_each with Lambda
template<typename T>
double Mean04(const std::vector<T> &v) {
    if (v.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    std::for_each(v.begin(), v.end(), [&sum](const T& val) { sum += val; });
    return sum / v.size();
}

// Mean05: std::reduce (C++17)
template<typename T>
double Mean05(const std::vector<T> &v) {
    if (v.empty()) { 
        return 0.0;
    }
    double sum = std::reduce(v.begin(), v.end(), 0.0);
    return sum / v.size();
}

// Mean06: Index-based Loop
template<typename T>
double Mean06(const std::vector<T> &v) {
    if (v.empty()) { 
        return 0.0;
    }
    double sum = 0.0;
    for (size_t i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    return sum / v.size();
}

// Variance01: Two-Pass with Loop
template<typename T>
double Variance01(const std::vector<T> &v) {
    if (v.empty()) { 
        return 0.0;
    }
    double mean = Mean01(v);
    double variance = 0.0;
    for (const T& val : v) {
        variance += (val - mean) * (val - mean);
    }
    return variance / v.size();
}

// Variance02: Using std::accumulate
template<typename T>
double Variance02(const std::vector<T> &v) {
    if (v.empty()) {
        return 0.0;
    }
    double mean = Mean01(v);
    double variance = std::accumulate(v.begin(), v.end(), 0.0,
        [mean](double acc, const T& val) {
            return acc + (val - mean) * (val - mean);
        });
    return variance / v.size();
}

// Variance03: Single-Pass Algorithm
template<typename T>
double Variance03(const std::vector<T> &v) {
    if (v.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    double sum_sq = 0.0;
    for (const T& val : v) {
        sum += val;
        sum_sq += val * val;
    }
    double mean = sum / v.size();
    return (sum_sq / v.size()) - (mean * mean);
}

#endif // MV_H
