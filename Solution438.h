#pragma once
#include <vector>
#include <string>
using namespace std;
class Solution438
{
public:
    vector<int> findAnagrams(string s, string p) {
        int len_s = s.size(), len_p = p.size();
        vector<int> ans;
        if (len_s < len_p)
            return ans;
        int cnt[26] = { 0 };
        int cnt2[26] = {0};
        int start = 0;
        for (int i = start; i < len_p; i++) {
            cnt[p[i] - 'a']++;
            cnt2[s[i] - 'a']++;
        }
        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != cnt2[i]) {
                flag = false;
                break;
            }
        }
        if (flag)
            ans.push_back(start);
        for (start = 1; start < len_s - len_p + 1; start++) {
            cnt2[s[start - 1] - 'a']--;
            cnt2[s[start + len_p - 1] - 'a']++;
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] != cnt2[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(start);
        }
        return ans;
    }
};

