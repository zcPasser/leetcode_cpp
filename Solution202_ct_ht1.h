#pragma once
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        if (n == 1)
            return true;
        unordered_set<int> se;
        int sum = 0;
        while (true) {
            while (n > 0) {
                int a = n % 10;
                n /= 10;
                sum += a * a;
            }
            n = sum, sum = 0;
            if (n == 1)
                return true;
            else if (se.count(n))
                return false;
            else
                se.insert(n);
        }
        return false;
    }
};
