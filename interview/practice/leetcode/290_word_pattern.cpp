#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
bool wordPattern(string pattern, string str) {
    unordered_map< char, string > match_map;
    unordered_map< string, char > reverse_match_map;
    vector< string > all_strings;

    int flag = 0;
    int start = 0, end = 0;
    while (start < str.size()) {
        end = str.find_first_of(' ', start);
        if (end != std::string::npos) {
            if (end > start) {
                all_strings.push_back(str.substr(start, end - start));
            }
        } else {
            break;
        }
        start = end + 1;
    }
    if (!str.substr(start).empty()) {
        all_strings.push_back(str.substr(start));
    }

    // test split
    // for (auto &a : all_strings) {
    //    std::cout << "a: " << a << std::endl;
    //}
    if (pattern.size() != all_strings.size()) {
        return false;
    }
    for (int i = 0; i < pattern.size(); i++) {
        if (match_map.find(pattern[i]) != match_map.end()) {
            if (match_map[pattern[i]] != all_strings[i]) {
                return false;
            }
        } else {
            match_map[pattern[i]] = all_strings[i];
        }
        if (reverse_match_map.find(all_strings[i]) != reverse_match_map.end()) {
            if (reverse_match_map[all_strings[i]] != pattern[i]) {
                return false;
            }
        } else {
            reverse_match_map[all_strings[i]] = pattern[i];
        }
    }
    return true;
}

int main() {
    std::cout << wordPattern("abba", "dog cat cat dog") << std::endl;
    std::cout << wordPattern("abba", "dog dog cat dog") << std::endl;
    std::cout << wordPattern("abba", "dog dog dog dog") << std::endl;
    std::cout << wordPattern("aaa", "dog dog dog dog") << std::endl;
    std::cout << wordPattern("abba", "  ") << std::endl;
}
