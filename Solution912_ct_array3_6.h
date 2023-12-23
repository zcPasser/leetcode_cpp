#pragma once
#include <vector>
using namespace std;
class Solution {
private:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;
        int mid = (right - left) / 2 + left;
        // ��
        // �ȷֵ� curSize=1��������Ĭ�ϴ�1��ʼ
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        // ��
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
        // �鲢����-�ݹ���ʽ
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;
        mergeSort(nums, 0, nsSize - 1);

        return nums;
    }
};
