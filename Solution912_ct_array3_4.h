#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 插入排序
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;
        // 第一个元素被认为已经被排序
        for (int i = 1; i < nsSize; i++) {
            // 两元素递增排序，则直接插入
            if (nums[i] >= nums[i - 1])
                continue;
            // 二分查找，时间复杂度logn
            int l = 0, r = i - 1;
            while (l <= r) {
                int mid = (r - l) / 2 + l;
                // r右侧元素均大于 nums[i]，即 r 及其左侧元素均小于等于nums[i]
                if (nums[i] < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            // 稳定排序，依次排列
            int idx = r + 1;
            int tmp = nums[i];
            // 将当前 i 元素插入在 index 位置，index ~ i - 1 元素依次后移，时间复杂度n
            for (int k = i; k >= idx + 1; --k) {
                nums[k] = nums[k - 1];
            }
            nums[idx] = tmp;
        }

        return nums;
    }
};
