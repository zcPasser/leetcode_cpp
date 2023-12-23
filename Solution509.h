#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;
        int preNum1 = 0, preNum2 = 1;
        int curNum = 0;
        for (int i = 2; i <= n; i++) {
            curNum = preNum1 + preNum2;
            preNum1 = preNum2;
            preNum2 = curNum;
        }
        return curNum;
    }
};

