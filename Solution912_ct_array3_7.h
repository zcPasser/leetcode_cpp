#pragma once
#include <vector>
using namespace std;
class Solution {
private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;
        //int idx = rand() % (right - left + 1) + left;
        //swap(nums[left], nums[idx]);
        //int pivot = nums[idx];
        // 基准元素
        // 可以随机化
        int pivot = nums[left];
        int l = left, r = right;
        while (l < r)
        {
            // 从右往左 找 比当前基准元素 小的 值
            while (l < r && nums[r] >= pivot)
                r--;
            //  找到 则交换
            if (l < r)
                nums[l] = nums[r];
            // 从左往右 找 比当前基准元素 大的 值
            while (l < r && nums[l] <= pivot)
                l++;
            if (l < r)
                nums[r] = nums[l];
                
        }
        // 交换基准
        nums[l] = pivot;
        // 确定了 基准元素的最终位置
        // 递归 左边 和 右边
        quickSort(nums, left, l - 1);
        quickSort(nums, l + 1, right);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        // 快速排序
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;
        quickSort(nums, 0, nsSize - 1);

        return nums;
    }
};
