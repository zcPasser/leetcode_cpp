#include<vector>
class Solution {
private:
    int maxLength(const std::vector<int>& a, const std::vector<int>& b, int aBegin, int bBegin, int size) {
        int cnt = 0, ans = 0;
        for (int i = 0; i < size; ++i) {
            if (a[aBegin + i] == b[bBegin + i])
                ++cnt;
            else {                
                
                cnt = 0;
            }
            ans = std::max(ans, cnt);
        }
        return ans;
    }
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        using namespace std;
        int nums1Size = nums1.size(), nums2Size = nums2.size();
        int ans = 0, tmpSize = 0;
        for (int i = 0; i < nums1Size; ++i) {
            tmpSize = min(nums2Size, nums1Size - i);
            ans = max(ans, maxLength(nums1, nums2, i, 0, tmpSize));
        }
        for (int i = 0; i < nums2Size; ++i) {
            tmpSize = min(nums1Size, nums2Size - i);
            ans = max(ans, maxLength(nums1, nums2, 0, i, tmpSize));
        }
        
        return ans;
    }
};

