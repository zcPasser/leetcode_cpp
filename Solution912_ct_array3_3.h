#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // ц╟ещеепР
        int nsSize = nums.size();
        if (nsSize < 2)
            return nums;
        for (int i = 0; i < nsSize - 1; i++) {
            bool isDone = true;
            for (int j = 0; j < nsSize - 1 - i; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    isDone = false;
                }
            }
            if (isDone)
                break;
        }
        
        return nums;
    }
};
