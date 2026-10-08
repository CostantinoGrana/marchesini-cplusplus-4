#ifndef RIBALTA_H
#define RIBALTA_H

#include <vector>
#include <algorithm>
#include <iterator>

// Ribalta01: Manual Loop with Two Pointers (by index)
template<typename T>
void Ribalta01(std::vector<T> &v) {
    size_t left = 0;
    size_t right = v.size() - 1;
    while (left < right) {
        std::swap(v[left], v[right]);
        ++left;
        --right;
    }
}

// Ribalta02: Manual Loop with Iterators
template<typename T>
void Ribalta02(std::vector<T> &v) {
    auto left = v.begin();
    auto right = v.end() - 1;
    while (left < right) {
        std::swap(*left, *right);
        //std::iter_swap(left, rigt);
        ++left;
        --right;
    }
}

// Ribalta03: Using std::reverse
template<typename T>
void Ribalta03(std::vector<T> &v) {
    std::reverse(v.begin(), v.end());
}

// Ribalta04: Manual loop from both ends
template<typename T>
void Ribalta04(std::vector<T> &v) {
    for (size_t i = 0; i < v.size() / 2; ++i) {
        std::swap(v[i], v[v.size() - 1 - i]);
    }
}

// Ribalta05: Using std::swap_ranges and reverse iterators
template<typename T>
void Ribalta05(std::vector<T> &v) {
    std::swap_ranges(v.begin(), v.begin() + v.size() / 2, v.rbegin());
}

#endif // RIBALTA_H
