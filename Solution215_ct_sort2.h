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
        //�ѵĹ�����������м�Ԫ�ؿ�ʼ��ǰ���У���Ϊ�м�Ԫ�غ����Ԫ�ض���Ҷ�ӽڵ㣬����Ҫ���жѹ�����
        //����ÿ����Ҷ�ӽڵ㣬���� maxHeapify ��ȷ���Ե�ǰ�ڵ�Ϊ���������������ѵ����ʡ�
        for (int i = heapSize / 2; i >= 0; --i)
            maxHeapify(vec, i, heapSize);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        //����������ȡ K �����Ԫ�ء���ÿ����ȡ�󣬽����Ԫ�ؽ������ѵ�ĩβ������С heapSize��Ȼ���ٴε��� maxHeapify ��ά�����ѵ����ʡ�
        //ѭ�������󣬶Ѷ�Ԫ�ؾ��ǵ� K ��Ԫ�أ���������
        for (int i = heapSize - 1; i >= heapSize - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};

