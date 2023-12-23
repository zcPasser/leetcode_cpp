#pragma once
#include<string>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0;
        int i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 || j >= 0||carry!=0) {
            int a = i >= 0 ? num1[i] - '0' : 0, b = j >= 0 ? num2[j] - '0' : 0;
            int sum = a + b + carry;
            ans.push_back('0' + sum % 10);
            carry = sum / 10;
            i--, j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

