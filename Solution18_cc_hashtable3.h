#pragma once
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int nsSize = nums.size();
        if (nsSize < 4)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int a = 0; a < nsSize - 3; a++) {
            // һ����֦
            if (nums[a] > target && nums[a] >= 0)
                break;
            // aȥ��
            if (a > 0 && nums[a] == nums[a - 1])
                continue;
            // ��ȷ�� a
            for (int b = a + 1; b < nsSize - 2; b++) {
                long tmp = nums[a] + nums[b];
                // ������֦
                if (tmp > target && tmp >= 0)
                    break;
                // bȥ��
                if (b > a + 1 && nums[b] == nums[b - 1])
                    continue;
                
                int c = b + 1, d = nsSize - 1;
                while (c < d) {
                    if ((long)tmp + nums[c] + nums[d] < target)
                        c++;
                    else if ((long)tmp + nums[c] + nums[d] > target)
                        d--;
                    else {
                        ans.push_back({ nums[a], nums[b], nums[c], nums[d] });
                        // cȥ��
                        while (c < d && nums[c] == nums[c + 1])
                            c++;
                        // dȥ��
                        while (d > c && nums[d] == nums[d - 1])
                            d--;
                        c++;
                        d--;
                    }
                }
            }
        }
        return ans;
    }
};

