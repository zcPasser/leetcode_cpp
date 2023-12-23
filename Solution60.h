#pragma once
#include<string>
#include<vector>
class Solution {
private:
    int factorial(int n) {
        if (n < 3)
            return n;
        int ans = 1;
        while (n > 1) {
            ans *= n;
            --n;
        }
        return ans;
    }

public:
    std::string getPermutation(int n, int k) {
        using namespace std;
        int curLevel = n - 1;
        int nums = 0;
        vector<bool> used(n + 1, false);
        string ans = "";
        int rest = k;
        while (curLevel > 0) {
            nums = factorial(curLevel);
            for (int i = 1; i <= n; ++i) {
                if (!used[i]) {
                    rest -= nums;
                    if (rest <= 0) {
                        rest += nums;
                        --curLevel;
                        used[i] = true;
                        ans.push_back(i + '0');
                        break;
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i)
            if (!used[i])
                ans.push_back(i + '0');
        return ans;
    }
};

