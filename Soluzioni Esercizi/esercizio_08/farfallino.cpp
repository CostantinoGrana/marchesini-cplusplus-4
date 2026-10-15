#include "farfallino.h"
#include <algorithm>
#include <sstream>
#include <regex>

std::string CodificaFarfallino01(const std::string& input) {
    std::string result;
    for (char c : input) {
        result += c;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            result += 'f';
            result += c;
        }
        // result += c + 'f' + c; 
    }
    return result;
}


std::string CodificaFarfallino02(const std::string& input) {
    std::string result;
    std::string vowels = "aeiouAEIOU";
    for (char c : input) {
        result += c;
        if (vowels.find(c) != std::string::npos) {
            result += 'f';
            result += c;
        }
    }
    return result;
}


std::string CodificaFarfallino03(const std::string& input) {
    auto is_vowel = [](char c) -> bool {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    };
    
    std::string result;
    for (char c : input) {
        result += c;
        if (is_vowel(c)) {
            result += 'f';
            result += c;
        }
    }
    return result;
}


std::string CodificaFarfallino04(const std::string& input) {
    std::ostringstream oss;
    std::string vowels = "aeiouAEIOU";
    for (char c : input) {
        oss << c;
        if (vowels.find(c) != std::string::npos) {
            oss << 'f' << c;
        }
    }
    return oss.str();
}


std::string CodificaFarfallino05(const std::string& input) {
    std::regex vowel_pattern("([aeiouAEIOU])");
    return std::regex_replace(input, vowel_pattern, "$1f$1");
}