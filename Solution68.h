#pragma once
#include<vector>
#include<string>
class Solution {
private:
    std::string blank(int n) {
        return std::string(n, ' ');
    }
    // join 返回用 sep 拼接 [left, right) 范围内的 words 组成的字符串
    std::string join(std::vector<std::string>& words, int left, int right, std::string sep) {
        using namespace std;
        string s = words[left];
        for (int i = left + 1; i < right; ++i) {
            s += sep + words[i];
        }
        return s;
    }
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        using namespace std;
        vector<string> ans;
        int right = 0, n = words.size();
        while (true) {
            int left = right;
            int sumLen = 0;
            while (right < n && sumLen + words[right].size() + right - left <= maxWidth) {
                sumLen += words[right++].size();
            }
            if (right == n) {
                string s = join(words, left, n, " ");
                ans.emplace_back(s + blank(maxWidth - s.size()));
                return ans;
            }
            int numWords = right - left;
            int numSpaces = maxWidth - sumLen;
            if (numWords == 1) {
                ans.emplace_back(words[left] + blank(numSpaces));
                continue;
            }
            int avgSpaces = numSpaces / (numWords - 1);
            int extraSpaces = numSpaces % (numWords - 1);
            string s1 = join(words, left, left + extraSpaces + 1, blank(avgSpaces + 1));
            string s2 = join(words, left + extraSpaces + 1, right, blank(avgSpaces));
            ans.emplace_back(s1 + blank(avgSpaces) + s2);
        }
        return ans;
    }
};

