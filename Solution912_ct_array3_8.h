#pragma once
#include <vector>
using namespace std;
class Solution {
private:
    void buildMaxHeap(vector<int>& nums) {
        int nsSize = nums.size();
        // 从最后一个堆 开始 建立最大堆
        // 自底向上
        for (int i = (nsSize - 1) / 2; i >= 0; i--) {
            maxHeapify(nums, i, nsSize);
        }
        
    }
    void maxHeapify(vector<int>& nums, int i, int n) {
        // 从当前节点 最大堆，自顶向下。
        while (2 * i + 1 < n) {
            int lChild = 2 * i + 1;
            int rChild = 2 * i + 2;
            int large = i;
            if (lChild < n && nums[large] < nums[lChild])
                large = lChild;
            if (rChild < n && nums[large] < nums[rChild])
                large = rChild;
            // 如果发生交换，还需要 递归 最大化堆 其 子树
            if (large != i) {
                swap(nums[i], nums[large]);
                i = large;
            }
            else
                break;
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        // 堆排序
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;
        // 建立 最大堆
        buildMaxHeap(nums);
        // nums[0]为最大值
        // 每次将 当前最大值nums[0] 和 当前最大堆的 最有一个元素交换
        // 缩小最大堆规模，重新最大化堆。
        for (int i = nsSize - 1; i >= 1; i--) {
            swap(nums[0], nums[i]);
            nsSize--;
            maxHeapify(nums, 0, nsSize);
        }

        return nums;
    }
};
