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
        // [left, right) ������滻 k ���ַ����Եõ�ֻ��һ���ַ����Ӵ�
        while (right < sSize) {
            freq[s[right] - 'A']++;
            // ������ά�� maxCount����Ϊÿһ���ұ߽����һ���ַ����ַ�Ƶ�����ӣ��Ż�ʹ�� maxCount ����
            // ͳ�� ��ǰ������ �ַ�Ƶ�������ַ��ĸ���
            maxCnt = max(maxCnt, freq[s[right] - 'A']);
            right++;
            if (right - left > maxCnt + k) {
                // ˵����ʱ k ������
                // ���������������ֵ��ַ��滻�Ժ󣬶�����������������Ĵ��ڣ����ʱ����Ҫ������߽������ƶ�
                // �Ƴ��������ڵ�ʱ��Ƶ��������Ҫ��Ӧ��������
                freq[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};

