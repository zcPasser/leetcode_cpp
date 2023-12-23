#pragma once
#include <vector>
using namespace std;
class Solution {
private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;
        //int idx = rand() % (right - left + 1) + left;
        //swap(nums[left], nums[idx]);
        //int pivot = nums[idx];
        // ��׼Ԫ��
        // ���������
        int pivot = nums[left];
        int l = left, r = right;
        while (l < r)
        {
            // �������� �� �ȵ�ǰ��׼Ԫ�� С�� ֵ
            while (l < r && nums[r] >= pivot)
                r--;
            //  �ҵ� �򽻻�
            if (l < r)
                nums[l] = nums[r];
            // �������� �� �ȵ�ǰ��׼Ԫ�� ��� ֵ
            while (l < r && nums[l] <= pivot)
                l++;
            if (l < r)
                nums[r] = nums[l];
                
        }
        // ������׼
        nums[l] = pivot;
        // ȷ���� ��׼Ԫ�ص�����λ��
        // �ݹ� ��� �� �ұ�
        quickSort(nums, left, l - 1);
        quickSort(nums, l + 1, right);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        // ��������
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;
        quickSort(nums, 0, nsSize - 1);

        return nums;
    }
};
