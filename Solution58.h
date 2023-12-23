#pragma once
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int sSize = s.size();
        int spaceIdx1 = -1, spaceIdx2 = sSize;
        for (int i = sSize - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                spaceIdx2 = i;
            }
            else
                break;
        }
        spaceIdx1 = spaceIdx2 - 1;
        while (spaceIdx1 >= 0 && s[spaceIdx1] != ' ')
            --spaceIdx1;
        return spaceIdx2 - spaceIdx1 - 1;
    }
};

