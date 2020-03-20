#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
  unordered_map<char, int> ss, tt;
  for (auto &s_char : s) {
    ++ss[s_char];
  }
  for (auto &t_char : t) {
    ++tt[t_char];
  }
  if (ss.size() != tt.size()) {
    return false;
  }
  for (auto &key : ss) {
    if (tt.find(key.first) == tt.end()) {
      return false;
    } else {
      if (ss[key.first] != tt[key.first]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  vector<vector<string>> results{{"anagram", "agraman"}, {"thief", "fieht"}, {"t", "tt"}, {"rrrr", ""}};
  for (auto & r : results) {
    std::cout<< isAnagram(r[0], r[1])<<std::endl;
  }
  return 0;
}
