#pragma once
#include <vector>
using namespace std;
class Solution {
private:
    void mergeSort(vector<int>& nums, int left, int mid, int right) {
        if (left >= right)
            return;
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
        // �鲢����-������ʽ
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;
        // ��ʶ��ǰ�ϲ���������Ĵ�С���� 1 ��֪�� n/2
        int curSize = 1;
        // ��ʶ��ǰҪ�ϲ�������������
        int leftStartIdx = 0, rightEndIdx = 0;
        while (curSize <= nsSize - 1) {
            // ���ڵ����� ����Ϊ curSize �� ������кϲ�
            for (leftStartIdx = 0; leftStartIdx < nsSize - 1; leftStartIdx += 2 * curSize) {
                int midIdx = min(leftStartIdx + curSize - 1, nsSize - 1);
                rightEndIdx = min(leftStartIdx + 2 * curSize - 1, nsSize - 1);
                mergeSort(nums, leftStartIdx, midIdx, rightEndIdx);
            }
            curSize += curSize;
        }

        return nums;
    }
};
