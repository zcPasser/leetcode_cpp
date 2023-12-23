#pragma once
#include<string>
using namespace std;
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string nStr = to_string(n);
        int nStrSize = nStr.size();
        int begin = nStrSize;
        for (int i = nStrSize - 1; i > 0; i--) {
            if (nStr[i] < nStr[i - 1]) {
                begin = i;
                nStr[i - 1]--;
            }
        }
        for (int i = begin; i < nStrSize; i++) {
            nStr[i] = '9';
        }
        return stoi(nStr);
    }
};

