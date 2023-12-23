#pragma once
#include <string>
using namespace std;
class Solution76
{
private:
    bool check(int * need, int * have) {
        for (int i = 65; i < 123; i++) {
            if (need[i] > have[i]) {
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int start = 0, end = 0;
        int len_s = s.size(), len_t = t.size();
        int ans_start = -1, ans = len_s + 1;
        if (len_s < len_t) {
            return "";
        }
        int need[123] = {0};
        int have[123] = {0};
        for (char ch : t) {
            need[ch]++;
        }
        while (end < len_s) {
            have[s[end]]++;
            while (check(need, have) && start <= end) {
                if (ans > (end - start + 1)) {
                    ans = end - start + 1;
                    ans_start = start;
                }
                have[s[start]]--;
                start++;
            }
            end++;
        }
        if (ans_start == -1) {
            return "";
        }
        return s.substr(ans_start, ans);
    }
};

