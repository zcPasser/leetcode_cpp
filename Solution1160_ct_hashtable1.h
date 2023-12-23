#pragma once
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charsCnt(26, 0);
        for (char& ch : chars)
            charsCnt[ch - 'a']++;
        int ans = 0;
        vector<int> wordCnt(26, 0);
        for (const string& word : words) {
            for (const char& ch : word)
                wordCnt[ch - 'a']++;
            bool sucess = true;
            for(int i=0;i<26;++i)
                if (wordCnt[i] > charsCnt[i]) {
                    sucess = false;
                    break;
                }
            if (sucess)
                ans += word.size();
            fill(wordCnt.begin(), wordCnt.end(), 0);
        }
        return ans;
    }
};
