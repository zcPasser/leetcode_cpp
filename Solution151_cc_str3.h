#pragma once
#include<string>
using namespace std;
class Solution {
private:
    void removeSpace(string& s)
    {
        int slow = 0, fast = 0;
        int sSize = s.size();
        while (fast < s.size())
        {
            if (s[fast] != ' ')
            {
                if (slow != 0)
                    s[slow++] = ' ';
                while (fast <sSize&& s[fast] != ' ')
                    s[slow++] = s[fast++];
            }
            fast++;
        }
        s.resize(slow);
    }
    void reverseStr(string& s, int left, int right)
    {
        while (left <= right)
        {
            swap(s[left++], s[right--]);
        }
        return;
    }
public:
    string reverseWords(string s) {
        removeSpace(s);
        int sSize = s.size();
        reverseStr(s, 0, sSize - 1);
        int left = 0, right = 0;
        for (; right < sSize; right++)
        {
            if (s[right] == ' ')
            {
                reverseStr(s, left, right - 1);
                left = right + 1;
            }
        }
        reverseStr(s, left, right - 1);
        return s;
    }
};

