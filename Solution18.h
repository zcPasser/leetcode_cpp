#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution18
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len_nums = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < len_nums - 3; i++) {
            //½èÖúÅÅÐò£¬¼ôÖ¦
            if (nums[i] > target && nums[i] >= 0)
                break;
            //¼ôÖ¦£¬×é¼äÖØ¸´
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < len_nums - 2; j++) {
                if (nums[i] + nums[j] > target && (nums[i] + nums[j]) >= 0)
                    break;
                if (j > (i + 1) && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1, right = len_nums - 1;
                while (left < right) {
                    int tmp = nums[i] + nums[j] + nums[left] + nums[right];
                    if (tmp < target)
                        left++;
                    else if (tmp > target)
                        right--;
                    else {
                        ans.push_back(vector<int>{ nums[i], nums[j], nums[left], nums[right] });
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++, right--;
                    }

                }
            }
        }
        return ans;
    }
};

