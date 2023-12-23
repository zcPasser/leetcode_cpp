#pragma once
#include<unordered_set>
#include<string>
class Solution {
private:
    int sSize;
    unsigned long long prime = 31;
public:
    std::string longestDupSubstring(std::string s) {
        using namespace std;
        sSize = s.size();
        int left = 1, right = sSize - 1;
        int pos = -1, len = 0;
        auto find = [&](int len) {
            unsigned long long hash = 0;
            unsigned long long power = 1;
            for (int i = 0; i < len; ++i) {
                hash = hash * prime + (s[i] - 'a');
                power *= prime;
            }
            unordered_set<unsigned long long> set{ hash };
            for (int i = len; i < sSize; ++i) {
                hash = hash * prime - power * (s[i - len] - 'a') + (s[i] - 'a');
                if (set.count(hash))
                    return (i - len + 1);
                set.insert(hash);
            }
            return -1;
        };
        int mid = 0, start = 0;
        while (left <= right) {
            mid = (right - left) / 2 + left;
            start = find(mid);
            if (start != -1) {
                len = mid;
                pos = start;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        if (pos == -1)
            return "";
        else
            return s.substr(pos, len);

    }
};

