#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    void maxHeapify(vector<int>& vec, int i, int heapSize) {
        int left = i * 2 + 1, right = i * 2 + 2, largest = i;
        if (left<heapSize && vec[left]>vec[largest])
            largest = left;
        if (right<heapSize && vec[right]>vec[largest])
            largest = right;
        if (largest != i) {
            swap(vec[i], vec[largest]);
            maxHeapify(vec, largest, heapSize);
        }
    }
    void buildMaxHeap(vector<int>& vec, int heapSize) {
        //堆的构建从数组的中间元素开始向前进行，因为中间元素后面的元素都是叶子节点，不需要进行堆构建。
        //对于每个非叶子节点，调用 maxHeapify 来确保以当前节点为根的子树满足最大堆的性质。
        for (int i = heapSize / 2; i >= 0; --i)
            maxHeapify(vec, i, heapSize);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        //从最大堆中提取 K 次最大元素。在每次提取后，将最大元素交换到堆的末尾，并减小 heapSize，然后再次调用 maxHeapify 来维护最大堆的性质。
        //循环结束后，堆顶元素就是第 K 大元素，返回它。
        for (int i = heapSize - 1; i >= heapSize - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};

