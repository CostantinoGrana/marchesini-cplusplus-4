#include "mv.h"
#include <numeric>
#include <cmath>
#include <algorithm>

double Mean01(const std::vector<int> &v) {
    if (v.empty()) { 
        return 0.0;
    }
    double sum = 0.0;
    for (int val : v) {
        sum += val;
    }
    return sum / v.size();
}

double Variance01(const std::vector<int> &v) {
    if (v.empty()) { 
        return 0.0;
    }
    double mean = Mean01(v);
    double variance = 0.0;
    for (int val : v) {
        variance += (val - mean) * (val - mean);
    }
    return variance / v.size();
}

// ========== MEAN SOLUTIONS ==========

// Mean02: std::accumulate
// Approach: Using STL algorithm
double Mean02(const std::vector<int> &v) {
    if (v.empty()) { 
        return 0.0;
    }
    double sum = std::accumulate(v.begin(), v.end(), 0.0);
    return sum / v.size();
}

// Mean03: Iterator-based Loop
// Approach: Using iterators explicitly
double Mean03(const std::vector<int> &v) {
    if (v.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (auto it = v.begin(); it != v.end(); ++it) {
        sum += *it;
    }
    return sum / v.size();
}

// Mean04: std::for_each with Lambda
// Approach: Using algorithm with lambda
double Mean04(const std::vector<int> &v) {
    if (v.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    std::for_each(v.begin(), v.end(), [&sum](int val) { sum += val; });
    return sum / v.size();
}

// Mean05: std::reduce (C++17)
// Approach: Parallel reduction algorithm
double Mean05(const std::vector<int> &v) {
    if (v.empty()) { 
        return 0.0;
    }
    double sum = std::reduce(v.begin(), v.end(), 0.0);
    return sum / v.size();
}

// Mean06: Index-based Loop
// Approach: Traditional C-style indexing
double Mean06(const std::vector<int> &v) {
    if (v.empty()) { 
        return 0.0;
    }
    double sum = 0.0;
    for (size_t i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    return sum / v.size();
}

// Variance02: Using std::accumulate
// Approach: Accumulate squared differences
double Variance02(const std::vector<int> &v) {
    if (v.empty()) {
        return 0.0;
    }
    double mean = Mean01(v);
    double variance = std::accumulate(v.begin(), v.end(), 0.0,
        [mean](double acc, int val) {
            return acc + (val - mean) * (val - mean);
        });
    return variance / v.size();
}

// Variance03: Single-Pass Algorithm
// Approach: Compute sum and sum of squares in one pass
double Variance03(const std::vector<int> &v) {
    if (v.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    double sum_sq = 0.0;
    for (int val : v) {
        sum += val;
        sum_sq += val * val;
    }
    double mean = sum / v.size();
    return (sum_sq / v.size()) - (mean * mean);
}