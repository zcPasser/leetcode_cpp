#pragma once
#include<string>
using namespace std;
class Solution151
{
public:
    void removeExtraSpace(string& s) {
        int lenS = s.size();
        int slowIdx = 0, fastIdx = 0;
        for (; fastIdx < lenS; fastIdx++) {
            if (s[fastIdx] != ' ') {
                if (slowIdx != 0) {
                    s[slowIdx++] = ' ';
                }
                while (fastIdx < lenS && s[fastIdx] != ' ') {
                    s[slowIdx++] = s[fastIdx++];
                }
            }

        }
        s.resize(slowIdx);
    }
    
    void reverse(string& s, int begin, int end) {
        if (!(0 <= begin && begin < end && end < s.size()))
            return;

        for (int i = begin, j = end; i < j; i++, j--) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
    
    string reverseWords(string s) {
        this->removeExtraSpace(s);
        this->reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                this->reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};

