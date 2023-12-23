#pragma once
#include<string>
#include<limits>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int sSize = s.size();
        int beginIdx = sSize;
        int flag = 0;
        // 处理 前导空格 和 正负号
        for (int i = 0; i < sSize; i++) {
            if (s[i] == ' ') {
                continue;
            }
            else if (s[i] == '+') {
                flag = 1;
                beginIdx = i + 1;
                break;
            }
            else if (s[i] == '-') {
                flag = -1;
                beginIdx = i + 1;
                break;
            }
            else if ('0' <= s[i] && s[i] <= '9') {
                flag = 1;
                beginIdx = i;
                break;
            }
            else
                break;
        }
        if (beginIdx == sSize)
            return 0;
        int ans = 0;

        int m1 = INT_MAX / 10, m2 = INT_MAX % 10;
        int n1 = INT_MIN / 10, n2 = INT_MIN % 10;

        for (int i = beginIdx; i < sSize; i++) {
            if (s[i] < '0' || s[i] > '9')
                break;
            int digit = s[i] - '0';
            if (flag == 1) {
                if (ans > m1 || (ans == m1 && digit > m2))
                    return INT_MAX;
            }
            else {
                digit *= flag;
                if (ans > 0) {
                    ans *= flag;  
                }              
                if (ans < n1 || (ans == n1 && digit < n2))
                    return INT_MIN;
            }
            ans = ans * 10 + digit;
        }
        return ans;
    }
};

