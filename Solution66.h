#pragma once
#include<vector>
class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        using namespace std;
        int digitsSize = digits.size();
        int carry = 1;
        int bitSum = 0;
        for (int i = digitsSize - 1; i >= 0; --i) {
            bitSum = digits[i] + carry;
            carry = bitSum / 10;
            digits[i] = bitSum % 10;
            if (carry == 0)
                break;
        }
        if (carry > 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};
