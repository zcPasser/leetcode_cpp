#pragma once
#include<limits>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            if (divisor == -1)
                return INT_MAX;
            if (divisor == 1)
                return INT_MIN;
        }
        if (divisor == INT_MIN)
            return dividend == INT_MIN ? 1 : 0;
        if (divisor == 0)
            return 0;
        bool isNeg = false;
        if (dividend > 0) {
            dividend = -dividend;
            isNeg = !isNeg;
        }
        if (divisor > 0) {
            divisor = -divisor;
            isNeg = !isNeg;
        }

        auto quickMul = [](int x, int y, int z) {
            int ans = 0, add = y;
            while (z) {
                if (z & 1) {
                    if (ans < x - add)
                        return false;
                    ans += add;
                }
                if (z != 1) {
                    if (add < x - add)
                        return false;
                    add <<= 1;
                }
                z >>= 1;
            }
            return true;
        };
        int left = 1, right = INT_MAX, ans=0;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (quickMul(dividend, divisor, mid)) {
                ans = mid;
                if (mid == INT_MAX)
                    break;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return isNeg ? -ans : ans;
    }
};

