#pragma once
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int sSize = s.size(), n = words[0].size(), m = words.size();
        for (int i = 0; i < n && (i + m * n) <= sSize; i++) {
            unordered_map<string, int> differ;
            for (int j = 0; j < m; j++) {
                ++differ[s.substr(i + j * n, n)];
            }
            for (const string& word : words) {
                if (--differ[word] == 0)
                    differ.erase(word);
            }
            for (int start = i; start < sSize - m * n + 1; start += n) {
                if (start != i) {
                    string word = s.substr(start + (m - 1) * n, n);
                    if (++differ[word] == 0)
                        differ.erase(word);
                    word = s.substr(start - n, n);
                    if (--differ[word] == 0)
                        differ.erase(word);
                }
                if (differ.empty())
                    ans.push_back(start);
            }
        }
        return ans;
    }
};

