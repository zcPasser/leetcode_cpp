#pragma once
#include<string>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int sSize = s.size();
        if (sSize < 2)
            return sSize;
        // step1:维护的变量
        map<char, int> winMap;
        // step2:窗口边界
        int beginWin = 0, endWin = 0;
        
        while (endWin < sSize) {
            // step3:合法更新
            winMap[s[endWin]]++;
            // 当前窗口的子序列满足条件，更新 目标。
            if ((endWin - beginWin + 1) == winMap.size()) {
                ans = max(ans, endWin - beginWin + 1);
            }
            // step4: 非法更新
            // 当前窗口的子序列 不满足条件， 开始收缩。
            while ((endWin - beginWin + 1) > winMap.size()) {
                winMap[s[beginWin]]--;
                if (winMap[s[beginWin]] == 0) {
                    winMap.erase(s[beginWin]);
                }
                // 窗口左边界移动
                beginWin++;
            }
            // 窗口 正常扩展，右边界 移动。 
            endWin++;
        }
        return ans;
    }
};