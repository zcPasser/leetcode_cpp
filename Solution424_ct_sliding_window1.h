#pragma once
#include<vector>
#include<string>]
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int sSize = s.size();
        if (sSize < 2)
            return sSize;
        int left = 0, right = 0;
        int ans = 0;
        int maxCnt = 0;
        vector<int> freq(26, 0);
        // [left, right) 内最多替换 k 个字符可以得到只有一种字符的子串
        while (right < sSize) {
            freq[s[right] - 'A']++;
            // 在这里维护 maxCount，因为每一次右边界读入一个字符，字符频数增加，才会使得 maxCount 增加
            // 统计 当前区间内 字符频数最大的字符的个数
            maxCnt = max(maxCnt, freq[s[right] - 'A']);
            right++;
            if (right - left > maxCnt + k) {
                // 说明此时 k 不够用
                // 把其它不是最多出现的字符替换以后，都不能填满这个滑动的窗口，这个时候须要考虑左边界向右移动
                // 移出滑动窗口的时候，频数数组须要相应地做减法
                freq[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};

