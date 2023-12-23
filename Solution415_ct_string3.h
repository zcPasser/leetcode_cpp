#pragma once
#include<string>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;
        int carry = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || carry != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int res = x + y + carry;
            ans.push_back('0' + res % 10);
            carry = res / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
