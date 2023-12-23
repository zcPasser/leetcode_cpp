#pragma once
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        string ans;
        int num1Size = num1.size(), num2Size = num2.size();
        vector<int> ansArr(num1Size + num2Size, 0);
        for (int i = num1Size - 1; i >= 0; i--) {
            int a = num1[i] - '0';
            for (int j = num2Size - 1; j >= 0; j--) {
                int b = num2[j] - '0';
                ansArr[i + j + 1] += a * b;
            }
        }
        for (int i = num1Size + num2Size - 1; i > 0; i--) {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }
        int idx = ansArr[0] == 0 ? 1 : 0;
        for (int i = idx; i < num1Size + num2Size; i++) {
            ans.push_back(ansArr[i] + '0');
        }
        return ans;
    }
};

