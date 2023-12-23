#pragma once
#include<string>
class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        using namespace std;
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int aSize = a.size(), bSize = b.size();
        int size = max(aSize, bSize);
        int carry = 0;
        for (int i = 0; i < size; ++i) {
            carry += i < aSize ? (a[i] == '1') : 0;
            carry += i < bSize ? (b[i] == '1') : 0;
            ans.push_back(carry % 2 + '0');
            carry /= 2;
        }
        if (carry > 0)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
