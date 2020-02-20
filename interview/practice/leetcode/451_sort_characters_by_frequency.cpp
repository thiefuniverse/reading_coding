#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
string frequencySort(string s) {
    vector< int > char_store(256, 0);
    for (auto &c : s) {
        char_store[c]++;
    }
    unordered_map< int, vector< int > > freq_map;
    unordered_set< int > freq;
    for (int i = 0; i < 256; i++) {
        if (char_store[i] > 0) {
            freq_map[char_store[i]].push_back(i);
            freq.insert(char_store[i]);
        }
    }
    priority_queue< int > p;
    for (auto &f : freq) {
        p.push(f);
    }
    string result;
    while (!p.empty()) {
        auto max_freq = p.top();
        p.pop();
        for (auto &freq_char : freq_map[max_freq]) {
            result += string(max_freq, char(freq_char));
        }
    }
    return result;
}

string frequencySort2(string s) {
    vector< pair< char, int > > char_store(256);
    for (auto &c : s) {
        char_store[c].first = c;
        char_store[c].second++;
    }
    sort(char_store.begin(), char_store.end(), [](pair< char, int > &a, pair< char, int > &b) { return a.second > b.second; });
    string result;
    for (auto &i : char_store) {
        result.append(i.second, i.first);
    }
    return result;
}
int main() {
    std::cout << frequencySort2("tree") << std::endl;
    std::cout << frequencySort2("cccaaa") << std::endl;
    std::cout << frequencySort2("bbbbbbccccccccmBAaaa") << std::endl;
    return 0;
}
