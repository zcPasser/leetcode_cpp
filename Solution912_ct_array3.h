#pragma once
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Ͱ����
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;
        int maxVal = nums[0], minVal = nums[0];
        // ͳ�� ��ֵ��Χ
        for (int i = 0; i < nsSize; i++) {
            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[i]);
        }
        int bucketNums = 5;
        int bucketSize = (maxVal - minVal) / bucketNums + 1;
        // ���� Ͱ
        vector<vector<int>> buckets(bucketNums, vector<int>());
        // ����
        // ��ͬͰ �� ������ǰԪ�� �� ��СֵΪ��׼
        for (int num : nums) {
            int bucketIdx = (num - minVal) / bucketSize;
            buckets[bucketIdx].emplace_back(num);
        }
        // Ͱ�����򣺵ݹ� | Ͱ����
        for (int i = 0; i < bucketNums; i++) {
            sort(buckets[i].begin(), buckets[i].end());
        }
        int idx = 0;
        // Ͱ������Ͱ������Ͱ���������������
        for (auto& bucket : buckets) {
            for (int num : bucket) {
                nums[idx++] = num;
            }
        }
        return nums;
    }
};
