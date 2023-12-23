#pragma once
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
private:
    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
public:
    int romanToInt(string s) {
        int ans = 0;
        int sSize = s.size();
        for (int i = 0; i < sSize; i++) {
            int val = symbolValues[s[i]];
            if (i < (sSize - 1) && val < symbolValues[s[i + 1]])
                ans -= val;
            else
                ans += val;
        }
        return ans;
    }
};

