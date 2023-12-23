#pragma once
#include<string>
using namespace std;
class Solution {
private:
    void reverse(string& s, int left, int right)
    {
        while (left <= right)
        {
            swap(s[left++], s[right--]);
        }
        return;
    }
public:
    /// <summary>
    /// for(int i=0;i<sSize;i+=step)
    /// {
    ///     if(i+k<=sSize)
    ///         reverse(s, i, i + k - 1);
    ///     else
    ///         reverse(s, i, sSize - 1);
    /// }
    /// </summary>
    /// <param name="s"></param>
    /// <param name="k"></param>
    /// <returns></returns>
    string reverseStr(string s, int k) {
        int sSize = s.size();
        if (sSize < k)
        {
            this->reverse(s, 0, sSize - 1);
            return s;
        }
        int step = 2 * k;
        int loop = sSize / step;
        int rest = sSize % step;
        int idx = 0;
        for (int i = 0; i < loop; ++i)
        {
            idx = i * step;
            this->reverse(s, idx, idx + k - 1);
        }
        if (rest < k)
            this->reverse(s, sSize - rest, sSize - 1);
        else
            this->reverse(s, sSize - rest, sSize - rest + k - 1);
        return s;
    }
};
