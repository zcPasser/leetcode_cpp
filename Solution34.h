#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = this->getLeftBorder(nums, target);
        int rightBorder = this->getRightBorder(nums, target);
        if (leftBorder == -2 || rightBorder == -2) {
            return { -1, -1 };
        }
        if ((rightBorder - leftBorder) > 1) {
            return { leftBorder + 1, rightBorder - 1 };
        }
        return { -1, -1 };
    }
private:
    int getRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] >= target) {
                right = mid - 1;
                leftBorder = right;
            }
            else {
                left = mid + 1;
            }
        }
        return leftBorder;
    }
};