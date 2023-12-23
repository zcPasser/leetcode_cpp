#pragma once
#include <vector>
using namespace std;
class Solution {
private:
    void mergeSort(vector<int>& nums, int left, int mid, int right) {
        if (left >= right)
            return;
        // 治
        vector<int> ans(right - left + 1, 0);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
                ans[k++] = nums[i++];
            else
                ans[k++] = nums[j++];
        }
        while (i <= mid) {
            ans[k++] = nums[i++];
        }
        while (j <= right) {
            ans[k++] = nums[j++];
        }
        copy(ans.begin(), ans.end(), nums.begin() + left);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        // 归并排序-迭代形式
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;
        // 标识当前合并的子数组的大小，从 1 已知到 n/2
        int curSize = 1;
        // 标识当前要合并的子数组的起点
        int leftStartIdx = 0, rightEndIdx = 0;
        while (curSize <= nsSize - 1) {
            // 相邻的两个 长度为 curSize 的 区间进行合并
            for (leftStartIdx = 0; leftStartIdx < nsSize - 1; leftStartIdx += 2 * curSize) {
                int midIdx = min(leftStartIdx + curSize - 1, nsSize - 1);
                rightEndIdx = min(leftStartIdx + 2 * curSize - 1, nsSize - 1);
                mergeSort(nums, leftStartIdx, midIdx, rightEndIdx);
            }
            curSize += curSize;
        }

        return nums;
    }
};
