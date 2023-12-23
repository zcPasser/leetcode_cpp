#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int sSize = s.size();
        if (sSize < 2)
            return;
        int left = 0, right = sSize - 1;
        while (left <= right)
        {
            swap(s[left++], s[right--]);

        }
    }
};
