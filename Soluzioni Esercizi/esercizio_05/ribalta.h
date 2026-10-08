#ifndef RIBALTA_H
#define RIBALTA_H

#include <algorithm>
#include <iterator>
#include <type_traits>

// Helper to check if a type is iterable
template<typename T, typename = void>
struct is_iterable : std::false_type {};

template<typename T>
struct is_iterable<T, std::void_t<
    decltype(std::declval<T>().begin()),
    decltype(std::declval<T>().end())
>> : std::true_type {};

// Ribalta01: Container - Using std::reverse
template<typename Container>
typename std::enable_if<is_iterable<Container>::value>::type
Ribalta01(Container &c) {
    std::reverse(c.begin(), c.end());
}

// Ribalta02: Container - Manual loop with iterators
template<typename Container>
void Ribalta02(Container &c) {
    auto left = c.begin();
    auto right = c.end();
    if (left == right) return;
    --right;
    
    while (left != right) {
        std::iter_swap(left, right);
        ++left;
        if (left == right) break;
        --right;
    }
}

// Ribalta03: Container - Using std::swap_ranges with rbegin
template<typename Container>
void Ribalta03(Container &c) {
    auto dist = std::distance(c.begin(), c.end());
    if (dist <= 1) return;
    
    auto mid = c.begin();
    std::advance(mid, dist / 2);
    std::swap_ranges(c.begin(), mid, c.rbegin());
}


// Ribalta06: Container - For containers with random access
template<typename Container>
void Ribalta06(Container &c) {
    if (c.empty()) return;
    
    auto size = std::distance(c.begin(), c.end());
    auto left = c.begin();
    
    for (decltype(size) i = 0; i < size / 2; ++i) {
        auto right = c.begin();
        std::advance(right, size - 1 - i);
        std::iter_swap(left, right);
        ++left;
    }
}

// Ribalta07: Iterator-based - Using std::reverse
template<typename Iterator>
void Ribalta07(Iterator begin, Iterator end) {
    std::reverse(begin, end);
}

// Ribalta08: Iterator-based - Manual swap
template<typename Iterator>
void Ribalta08(Iterator begin, Iterator end) {
    if (begin == end) return;
    --end;
    
    while (begin != end) {
        std::iter_swap(begin, end);
        ++begin;
        if (begin == end) break;
        --end;
    }
}

#endif // RIBALTA_H
