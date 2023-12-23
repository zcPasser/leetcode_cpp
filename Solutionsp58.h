#pragma once
#include <string>
using namespace std;
class Solutionsp58
{
public:
    void reverse(string& s, int begin, int end) {
        if (!(0 <= begin && begin < end && end < s.size()))
            return;
            
        for (int i = begin, j = end; i < j; i++, j--) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }

    string reverseLeftWords(string s, int n) {
        int lenS = s.size();
        this->reverse(s, 0, n - 1);
        this->reverse(s, n, lenS - 1);
        this->reverse(s, 0, lenS - 1);
        return s;
    }
};

