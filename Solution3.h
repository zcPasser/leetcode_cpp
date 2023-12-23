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
        // step1:ά���ı���
        map<char, int> winMap;
        // step2:���ڱ߽�
        int beginWin = 0, endWin = 0;
        
        while (endWin < sSize) {
            // step3:�Ϸ�����
            winMap[s[endWin]]++;
            // ��ǰ���ڵ��������������������� Ŀ�ꡣ
            if ((endWin - beginWin + 1) == winMap.size()) {
                ans = max(ans, endWin - beginWin + 1);
            }
            // step4: �Ƿ�����
            // ��ǰ���ڵ������� ������������ ��ʼ������
            while ((endWin - beginWin + 1) > winMap.size()) {
                winMap[s[beginWin]]--;
                if (winMap[s[beginWin]] == 0) {
                    winMap.erase(s[beginWin]);
                }
                // ������߽��ƶ�
                beginWin++;
            }
            // ���� ������չ���ұ߽� �ƶ��� 
            endWin++;
        }
        return ans;
    }
};