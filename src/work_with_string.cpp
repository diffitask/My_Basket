#include "work_with_string.h"
#include <errors.h>
#include <algorithm>
#include <exception>
namespace {
void to_lower_rus(int &codepoint) {
    if (codepoint >= 1040 && codepoint <= 1071) {
        codepoint += 32;
    }
    if (codepoint == 1025) {
        codepoint = 1105;
    }
}
}  // namespace
pair<int, int> code_point(const string &u) {
    pair<int, int> result = {-1, -1};
    int l = u.length();
    if (l < 1) {
        return result;
    }
    unsigned char u0 = u[0];
    if (u0 >= 0 && u0 <= 127) {
        result.first = u0;
        result.second = 1;
        return result;
    }
    if (l < 2) {
        return result;
    }
    unsigned char u1 = u[1];
    if (u0 >= 192 && u0 <= 223) {
        result.first = (u0 - 192) * 64 + (u1 - 128);
        result.second = 2;
        return result;
    }
    if ((u[0] & 0xed) == 0xed && (u[1] & 0xa0) == 0xa0) {
        return result;  // code points, 0xd800 to 0xdfff
    }
    if (l < 3) {
        return result;
    }
    unsigned char u2 = u[2];
    if (u0 >= 224 && u0 <= 239) {
        result.first = (u0 - 224) * 4096 + (u1 - 128) * 64 + (u2 - 128);
        result.second = 3;
        return result;
    }
    if (l < 4) {
        return result;
    }
    unsigned char u3 = u[3];
    if (u0 >= 240 && u0 <= 247) {
        result.first = (u0 - 240) * 262144 + (u1 - 128) * 4096 +
                       (u2 - 128) * 64 + (u3 - 128);
        result.second = 4;
        return result;
    }
    return result;
}

std::string utf8_encode(uint32_t symbol) {
    char out[5] = {0x00, 0x00, 0x00, 0x00, 0x00};
    if (symbol <= 0x7F) {
        // ASCII
        out[0] = static_cast<char>(symbol);
        out[1] = 0;
    } else if (symbol <= 0x07FF) {
        // 2-byte unicode
        out[0] = static_cast<char>((((symbol >> 6) & 0x1F) | 0xC0));
        out[1] = static_cast<char>((((symbol >> 0) & 0x3F) | 0x80));
    } else if (symbol <= 0xFFFF) {
        // 3-byte unicode
        out[0] = static_cast<char>((((symbol >> 12) & 0x0F) | 0xE0));
        out[1] = static_cast<char>((((symbol >> 6) & 0x3F) | 0x80));
        out[2] = static_cast<char>((((symbol >> 0) & 0x3F) | 0x80));
    } else if (symbol <= 0x10FFFF) {
        // 4-byte unicode
        out[0] = static_cast<char>((((symbol >> 18) & 0x07) | 0xF0));
        out[1] = static_cast<char>((((symbol >> 12) & 0x3F) | 0x80));
        out[2] = static_cast<char>((((symbol >> 6) & 0x3F) | 0x80));
        out[3] = static_cast<char>((((symbol >> 0) & 0x3F) | 0x80));
    } else {
        // error - use replacement character
        out[0] = static_cast<char>(0xEF);
        out[1] = static_cast<char>(0xBF);
        out[2] = static_cast<char>(0xBD);
    }
    return static_cast<string>(out);
}

void from_str_to_codepoint(string old_s, std::vector<uint32_t> &vec) {
    if (old_s.empty()) {
        return;
    }
    std::string copy_s = old_s;
    std::transform(old_s.begin(), old_s.end(), old_s.begin(), ::tolower);
    std::string bad_str = "№";
    size_t index = old_s.find(bad_str);
    if (index != std::string::npos) {
        old_s.erase(index, bad_str.length());
    }

    std::vector<char> unexpected_chars = {
        ' ', ',', '\n', '\t', '\b', '\\', '\"', '-', '+', '/',
        ';', '#', '&',  '`',  '=',  '(',  ')',  '.', '%', '@'};
    for (auto t : unexpected_chars) {
        old_s.erase(std::remove(old_s.begin(), old_s.end(), t), old_s.end());
    }

    std::string new_s;
    auto [codepoint, symbol_size] = code_point(old_s);
    to_lower_rus(codepoint);
    vec.push_back(0);
    vec.push_back(codepoint);
    new_s.resize(old_s.size() - symbol_size);

    while (!new_s.empty()) {
        for (int i = symbol_size; i < old_s.size(); i++) {
            if (i - symbol_size >= new_s.size()) {
                throw err::InvalidString(copy_s);
            }
            new_s[i - symbol_size] = old_s[i];
        }

        auto [codepoint, symbol_size] = code_point(new_s);
        to_lower_rus(codepoint);
        vec.push_back(codepoint);
        old_s = new_s;
        new_s.resize(old_s.size() - symbol_size);
    }
}

uint32_t number_of_symbols(string old_s) {
    if (old_s.empty()) {
        return 0;
    }

    std::string new_s;
    int x = code_point(old_s).second;
    new_s.resize(old_s.size() - x);
    int counter = 1;
    while (!new_s.empty()) {
        for (int i = x; i < old_s.size(); i++) {
            new_s[i - x] = old_s[i];
        }
        x = code_point(new_s).second;
        old_s = new_s;
        new_s.resize(old_s.size() - x);
        counter++;
    }
    return counter;
}
