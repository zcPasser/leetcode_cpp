#pragma once
#include<string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hsSize = haystack.size(), nlSize = needle.size();
        for (int i = 0; i <= hsSize - nlSize; ++i)
        {
            int j = i, k = 0;
            while (k < nlSize && haystack[j++] == needle[k++])
            if (k == nlSize)
                return i;
        }
        return -1;
    }
};

