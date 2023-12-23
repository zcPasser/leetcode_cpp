#pragma once
#include<algorithm>
using namespace std;
class Solution {
public:
    // Å£¶Ùµü´ú¹«Ê½
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        double C = x, x0 = x;
        while (true)
        {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7)
                break;
            x0 = xi;
        }
        
        return int(x0);
    }
};

