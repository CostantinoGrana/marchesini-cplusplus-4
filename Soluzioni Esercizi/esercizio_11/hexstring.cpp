#include "hexstring.h"
#include <sstream>
#include <iomanip>
#include <cctype>

std::vector<int> HexStringToValues01(const std::string& s) {
    std::vector<int> result(8, 0);
    
    auto hex_to_int = [](char c) -> int {
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'A' && c <= 'F') return c - 'A' + 10;
        if (c >= 'a' && c <= 'f') return c - 'a' + 10;
        return 0;
    };
    
    for (size_t i = 0; i < s.size() && i < 16; i += 2) {
        int high = hex_to_int(s[i]);
        int low = (i + 1 < s.size()) ? hex_to_int(s[i + 1]) : 0;
        result[i / 2] = (high << 4) | low;
    }
    
    return result;
}


std::vector<int> HexStringToValues02(const std::string& s) {
    std::vector<int> result(8, 0);
    
    for (size_t i = 0; i < s.size() && i < 16; i += 2) {
        std::string hex_pair = s.substr(i, 2);
        result[i / 2] = std::stoi(hex_pair, nullptr, 16);
    }
    
    return result;
}


std::vector<int> HexStringToValues03(const std::string& s) {
    std::vector<int> result(8, 0);
    
    for (size_t i = 0; i < s.size() && i < 16; i += 2) {
        std::string hex_pair = s.substr(i, 2);
        std::stringstream ss;
        ss << std::hex << hex_pair;
        ss >> result[i / 2];
    }
    
    return result;
}


std::vector<int> HexStringToValues04(const std::string& s) {
    std::vector<int> result(8, 0);
    
    for (size_t i = 0; i < s.size() && i < 16; i += 2) {
        int val = 0;
        char c1 = std::toupper(s[i]);
        val = (c1 >= 'A') ? (c1 - 'A' + 10) : (c1 - '0');
        val <<= 4;
        
        if (i + 1 < s.size()) {
            char c2 = std::toupper(s[i + 1]);
            val |= (c2 >= 'A') ? (c2 - 'A' + 10) : (c2 - '0');
        }
        
        result[i / 2] = val;
    }
    
    return result;
}
