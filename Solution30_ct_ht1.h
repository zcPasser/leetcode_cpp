#pragma once
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int wsSize = words.size(), wSize = words[0].size(), sSize = s.size();
        for (int i = 0; i < wSize && (i + wsSize * wSize <= sSize); ++i) {
            unordered_map<string, int> differ;
            for (int j = 0; j < wsSize; ++j)
                ++differ[s.substr(i + j * wSize, wSize)];
            for (const string& w : words)
                if (--differ[w] == 0)
                    differ.erase(w);
            for (int start = i; start < sSize - wsSize * wSize + 1; start += wSize) {
                if (start != i) {
                    string word = s.substr(start + (wsSize - 1) * wSize, wSize);
                    if (++differ[word] == 0)
                        differ.erase(word);
                    word = s.substr(start - wSize, wSize);
                    if (--differ[word] == 0)
                        differ.erase(word);
                }
                if (differ.empty())
                    ans.emplace_back(start);
            }
        }
        return ans;
    }
};

