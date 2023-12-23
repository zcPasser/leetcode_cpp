#pragma once
#include<string>
using namespace std;
class Solution541
{
private:
    void reverse(string& s, int begin, int end) {
        if (end >= s.size() || begin >= end)
            return;
        char tmp;
        while (begin < end) {
            tmp = s[begin];
            s[begin] = s[end];
            s[end] = tmp;
            begin++, end--;
        }
    }
public:
    string reverseStr(string s, int k) {
        int len_s = s.size();
        for (int i = 0; i < len_s; i += 2 * k) {
            if (i + k <= len_s) {
                this->reverse(s, i, i + k - 1);
            }
            else {
                this->reverse(s, i, len_s - 1);
            }
        }
        return s;
    }
};

