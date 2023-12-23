#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 希尔排序
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;
        // 间隔为d的为一组，增量 从大到小
        //
        for (int d = nsSize / 2; d >= 1; d /= 2) {
            // 一轮 希尔排序
            // 以d为增量距离的当前轮 其中一组的开头元素 [0, d)
            // 当前d 共有 d个序列，每个序列开头分别对应[0, d)
            for (int x = 0; x < d; x++) {
                // 对当前组 开始 插入排序
                // 默认 当前组 第一个元素 处在 有序队列中
                for (int i = x + d; i < nsSize; i += d) {
                    int tmp = nums[i];
                    int j = 0;
                    // 当前组 的 每一个元素 插入之前 已排序队列中。
                    // 插入位置：从后向前，找到第一个 <= 当前元素tmp的位置的下一个，过程中执行 覆盖。
                    for (j = i - d; j >= 0 && nums[j] > tmp; j -= d) {
                        nums[j + d] = nums[j];
                    }
                    // 插入位置
                    nums[j + d] = tmp;
                }
            }
        }

        return nums;
    }
};
