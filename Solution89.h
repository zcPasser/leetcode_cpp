#pragma once
#include<vector>
class Solution {
public:
    std::vector<int> grayCode(int n) {
        using namespace std;
        vector<int> ans;
        ans.push_back(0);
        int curSize = 1;
        while (n-- > 0) {
            curSize = ans.size();
            for (int i = curSize - 1; i >= 0; --i) {
                ans[i] <<= 1;
                ans.push_back(ans[i] + 1);
            }
        }
        return ans;
    }
};

