#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 计数排序
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;
        // 统计 范围，最小值、最大值
        int minVal = nums[0], maxVal = nums[0];
        for (int i = 0; i < nsSize; i++) {
            if (nums[i] < minVal)
                minVal = nums[i];
            if (nums[i] > maxVal)
                maxVal = nums[i];
        }
        // 以 最小值为基准，创建 计数数组
        vector<int> cnts(maxVal - minVal + 1, 0);
        for (int i = 0; i < nsSize; i++)
            ++cnts[nums[i] - minVal];
        int idx = 0;
        // 根据 计数结果，进行排序，同时 将基准 minVal 还原。
        for (int i = 0; i < cnts.size(); i++) {
            while (cnts[i]) {
                nums[idx++] = i + minVal;
                cnts[i]--;
            }
        }

        return nums;
    }
};
