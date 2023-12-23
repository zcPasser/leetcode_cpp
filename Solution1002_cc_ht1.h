#pragma once
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int wsSize = words.size();
        vector<string> ans;
        if (wsSize == 0)
            return ans;
        vector<int> cnts(26, 0), cntsOther(26, 0);
        for (char ch : words[0])
            cnts[ch - 'a']++;
        for (int i = 1; i < wsSize; ++i) {
            fill(cntsOther.begin(), cntsOther.end(), 0);
            for (char ch : words[i])
                cntsOther[ch - 'a']++;
            for (int j = 0; j < 26; j++)
                cnts[j] = min(cnts[j], cntsOther[j]);
        }
        for (int i = 0; i < 26; i++) {
            while (cnts[i] > 0) {
                ans.push_back(string(1, i + 'a'));
                cnts[i]--;
            }
        }
        return ans;
    }
};

