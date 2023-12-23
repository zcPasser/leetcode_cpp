#pragma once

using namespace std;
class Solution {
private:
    int getNum(int n) {
        int ans = 0;
        while (n) {
            int tmp = n % 10;
            n /= 10;
            ans += tmp * tmp;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        if (n == 1)
            return true;
        int fast = getNum(n), slow = n;
        // unse.insert(n);
        while (fast != 1 && fast != slow) {
            fast = getNum(getNum(fast));
            slow = getNum(slow);
        }
        return fast == 1;
    }
};

