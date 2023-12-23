#pragma once
using namespace std;
class Solution {
private:
    double quickPow(double x, long n) {
        double ans = 1.0;
        while (n > 0) {
            if ((n & 1) == 1) {
                ans *= x;
            }
            x *= x;
            n >>= 1;
        }
        return ans;
    }
public:
    double myPow(double x, int n) {
        if (x == 0 || x == 1.0 || n == 1)
            return x;
        if (n == 0)
            return 1;
        long b = n;
        return n < 0 ? 1.0 / quickPow(x, -b) : quickPow(x, b);
    }
};
