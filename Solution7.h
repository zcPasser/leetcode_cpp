#pragma once
#include<limits>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int m1 = INT_MAX / 10, m2 = INT_MAX % 10;
        int n1 = INT_MIN / 10, n2 = INT_MIN % 10;
        int ans = 0;
        while (x != 0) {
            int digit = x % 10;
            if (ans > m1 || (ans == m1 && digit > m2))
                return 0;
            if (ans < n1 || (ans == n1 && digit < n2))
                return 0;
            ans = ans * 10 + digit;
            x /= 10;
        }
        return ans;
    }
};

