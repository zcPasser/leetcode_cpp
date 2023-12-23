#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    void radixSort(vector<int>& nums) {
        int maxVal = nums[0];
        // 保证 正数；找到最大值；
        for (int& num : nums) {
            num += 50000;
            if (maxVal < num)
                maxVal = num;
        }
        int d = 1;
        int p = 10;
        // 通过 除法，得到 最大值的位数，也是循环次数。
        while (maxVal >= p) {
            maxVal /= 10;
            ++d;
        }
        vector<int> cnt(10, 0);        
        int i, j, k;
        int radix = 1;
        int nsSize = nums.size();
        vector<int> tmp(nsSize, 0);
        for (i = 0; i < d; i++) {
            // 计数数组 清零。
            std::fill(cnt.begin(), cnt.end(), 0);
            // 当前位 计数
            for (j = 0; j < nsSize; j++) {
                k = (nums[j] / radix) % 10;
                cnt[k]++;
            }
            // 当前位 根据计数结果，计算 当前轮排序后 每类的索引。
            for (j = 1; j < 10; j++) {
                cnt[j] += cnt[j - 1];
            }
            // 根据 索引，排序
            for (j = nsSize - 1; j >= 0; j--) {
                k = (nums[j] / radix) % 10;
                tmp[cnt[k] - 1] = nums[j];
                cnt[k]--;
            }
            // 排序结果 覆盖原数组
            copy(tmp.begin(), tmp.end(), nums.begin());
            // 位数迭代
            radix *= 10;
        }
        for (int& num : nums)
            num -= 50000;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        // 基数排序
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;

        radixSort(nums);

        return nums;
    }
};
