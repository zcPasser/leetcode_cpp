#pragma once
#include<string>
using namespace std;
class Solution {
private:
    string addStrings(const string& s1, const string& s2) {
        int i = s1.size() - 1, j = s2.size() - 1;
        int carry = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || carry != 0) {
            int a = i >= 0 ? s1[i] - '0' : 0;
            int b = j >= 0 ? s2[j] - '0' : 0;
            int sum = a + b + carry;
            ans.push_back('0' + sum % 10);
            carry = sum / 10;
            i--, j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        string ans = "0";
        int num1Size = num1.size(), num2Size = num2.size();
        for (int i = num2Size - 1; i >= 0; i--) {
            string cur = "";
            //num2 除了最低位以外，其余的每一位的运算结果都需要补 0。
            for (int j = num2Size - 1; j > i; j--)
                cur.push_back('0');
            int carry = 0;
            int a = num2[i] - '0';
            for (int j = num1Size - 1; j >= 0; j--) {
                int b = num1[j] - '0';
                int product = a * b + carry;
                cur.push_back('0' + product % 10);
                carry = product / 10;
            }
            while (carry != 0) {
                cur.push_back('0' + carry % 10);
                carry = carry / 10;
            }
            reverse(cur.begin(), cur.end());
            ans = addStrings(ans, cur);
        }
        return ans;
    }
};

