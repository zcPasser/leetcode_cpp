#pragma once
#include <vector>
using namespace std;
class Solution344
{
public:
    void reverseString(vector<char>& s) {
        int len_s = s.size();
        int left = 0, right = len_s - 1;
        while (left < right) {
            s[left] ^= s[right];
            s[right] ^= s[left];
            s[left] ^= s[right];
            left++, right--;
        }
        //char tmp;
        //while (left < right) {
        //    tmp = s[left];
        //    s[left] = s[right];
        //    s[right] = tmp;
        //    left++, right--;
        //}
    }
};

