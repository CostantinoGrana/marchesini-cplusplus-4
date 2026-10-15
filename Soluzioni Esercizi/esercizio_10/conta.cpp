#include "conta.h"
#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <regex>

int Conta01(const std::string& str) {
    int count = 0;
    bool in_word = false;
    
    for (char c : str) {
        if (c != ' ') {
            if (!in_word) {
                count++;
                in_word = true;
            }
        } else {
            in_word = false;
        }
    }
    
    return count;
}

int Conta02(const std::string& str) {
    std::istringstream iss(str);
    std::string word;
    int count = 0;
    
    while (iss >> word) {
        count++;
    }
    
    return count;
}

int Conta03(const std::string& str) {
    if (str.empty()) {
        return 0;
    }
    
    int count = 0;
    bool prev_space = true;
    
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] != ' ' && prev_space) {
            count++;
        }
        prev_space = (str[i] == ' ');
    }
    
    return count;
}

int Conta04(const std::string& str) {
    int count = 0;
    
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] != ' ') {
            if (i == 0 || str[i - 1] == ' ') {
                count++;
            }
        }
    }
    
    return count;
}


int Conta05(const std::string& str) {
    std::istringstream iss(str);
    return std::distance(
        std::istream_iterator<std::string>(iss),
        std::istream_iterator<std::string>()
    );
}

int ContaBonus(const std::string& str) {
    std::istringstream iss(str);
    int n = 0;
    for (auto it = std::istream_iterator<std::string>(iss); 
         it != std::istream_iterator<std::string>(); 
         ++it, ++n){}
    return n;
}

int Conta06(const std::string& str) {
    std::regex word_pattern("\\S+");
    
    auto words_begin = std::sregex_iterator(str.begin(), str.end(), word_pattern);
    auto words_end = std::sregex_iterator();
    
    return std::distance(words_begin, words_end);
}
