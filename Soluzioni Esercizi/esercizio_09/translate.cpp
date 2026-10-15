#include "translate.h"
#include <algorithm>
#include <unordered_map>
#include <regex>

void Translate01(std::string& s, const std::string& from_lst, const std::string& to_lst) {
    if (from_lst.size() != to_lst.size()) {
        return;
    }
    
    for (size_t i = 0; i < s.size(); ++i) {
        size_t pos = from_lst.find(s[i]);
        if (pos != std::string::npos) {
            s[i] = to_lst[pos];
        }
    }
}

void Translate02(std::string& s, const std::string& from_lst, const std::string& to_lst) {
    if (from_lst.size() != to_lst.size()) {
        return;
    }
    
    for (auto it = s.begin(); it != s.end(); ++it) {
        size_t pos = from_lst.find(*it);
        if (pos != std::string::npos) {
            *it = to_lst[pos];
        }
    }
}

void Translate03(std::string& s, const std::string& from_lst, const std::string& to_lst) {
    if (from_lst.size() != to_lst.size()) {
        return;
    }
    
    std::transform(s.begin(), s.end(), s.begin(), 
        [&from_lst, &to_lst](char c) {
            size_t pos = from_lst.find(c);
            return (pos != std::string::npos) ? to_lst[pos] : c;
        });
}

void Translate04(std::string& s, const std::string& from_lst, const std::string& to_lst) {
    if (from_lst.size() != to_lst.size()) {
        return;
    }
    
    std::unordered_map<char, char> trans_map;
    for (size_t i = 0; i < from_lst.size(); ++i) {
        trans_map[from_lst[i]] = to_lst[i];
    }
    
    for (char& c : s) {
        auto it = trans_map.find(c);
        if (it != trans_map.end()) {
            c = it->second;
        }
    }
}

void Translate05(std::string& s, const std::string& from_lst, const std::string& to_lst) {
    if (from_lst.size() != to_lst.size() || from_lst.empty()) {
        return;
    }

    std::string pattern = "[";
    for (char c : from_lst) {
        if (c == '\\' || c == ']' || c == '[' || c == '^' || c == '-') {
            pattern += '\\';
        }
        pattern += c;
    }
    pattern += "]";
    std::regex re(pattern);

    for (auto it = std::sregex_iterator(s.begin(), s.end(), re); it != std::sregex_iterator(); ++it) {
        size_t i = it->position();
        s[i] = to_lst[from_lst.find(s[i])];
    }
}
