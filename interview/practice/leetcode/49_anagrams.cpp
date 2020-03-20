#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// version 1
vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<string, vector<string>> result;
  for (auto &s : strs) {
    std::string another = s;
    std::sort(another.begin(), another.end());
    result[another].push_back(s);
  }
  vector<vector<string>> res;
  for (auto &k : result) {
    res.push_back(k.second);
  }
  return res;
}

int main() {
  vector<vector<string>>  tt{{"eat", "ate", "tan", "nat", "bat", "eta"}};
  for(auto & t : tt) {
    auto result = groupAnagrams(t);
    for (auto & rr : result ) {
      for (auto & r : rr) {
       std::cout << r<<" ";
      }
       std::cout << std::endl;
    }
  }
  return 0;
}
