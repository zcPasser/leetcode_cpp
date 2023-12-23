#pragma once
using namespace std;
class Solution {
public:
    // ¶þ·Ö·¨
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        int left = 0, right = x / 2;
        while (left < right)
        {
            int mid = (right + left + 1) / 2;
            if (mid <= x / mid)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};

