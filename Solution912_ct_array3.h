#pragma once
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 桶排序
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;
        int maxVal = nums[0], minVal = nums[0];
        // 统计 最值范围
        for (int i = 0; i < nsSize; i++) {
            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[i]);
        }
        int bucketNums = 5;
        int bucketSize = (maxVal - minVal) / bucketNums + 1;
        // 创建 桶
        vector<vector<int>> buckets(bucketNums, vector<int>());
        // 分组
        // 不同桶 的 键：当前元素 以 最小值为基准
        for (int num : nums) {
            int bucketIdx = (num - minVal) / bucketSize;
            buckets[bucketIdx].emplace_back(num);
        }
        // 桶内排序：递归 | 桶排序
        for (int i = 0; i < bucketNums; i++) {
            sort(buckets[i].begin(), buckets[i].end());
        }
        int idx = 0;
        // 桶间有序，桶内无序，桶内在逐个进行排序
        for (auto& bucket : buckets) {
            for (int num : bucket) {
                nums[idx++] = num;
            }
        }
        return nums;
    }
};
