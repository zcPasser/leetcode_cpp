#pragma once
#include<unordered_set>
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
        unordered_set<int> unse;
        // unse.insert(n);
        while (true) {
            if (n == 1)
                return true;
            if (unse.find(n) != unse.end())
                return false;
            unse.insert(n);
            n = getNum(n);  
        }
    }
};

