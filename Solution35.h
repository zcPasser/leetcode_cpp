#include <vector>

using namespace std;

#pragma once
class Solution35
{
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1; // ����target������ұյ������[left, right]
        while (left <= right) { // ��left==right������[left, right]��Ȼ��Ч
            int middle = left + ((right - left) / 2);// ��ֹ��� ��ͬ��(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target �������䣬����[left, middle - 1]
            }
            else if (nums[middle] < target) {
                left = middle + 1; // target �������䣬����[middle + 1, right]
            }
            else { // nums[middle] == target
                return middle;
            }
        }
        return right + 1;
    }
};

