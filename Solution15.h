#pragma once
#include<vector>
#include<algorithm>
using namespace std;
class Solution15
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len_nums = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < len_nums; i++) {
            if (nums[i] > 0)
                return ans;
            // nums[i] ȥ�أ��� �� ��Ԫ��� ȥ�ء�
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = len_nums - 1;
            while (left < right) {
                int tmp = nums[i] + nums[left] + nums[right];
                if (tmp == 0) {
                    ans.push_back(vector<int>({ nums[i], nums[left], nums[right] }));
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (tmp > 0)
                    right--;
                else
                    left++;
            }
        }
        return ans;
    }
};

