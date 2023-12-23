#pragma once
#include<string>
#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int sSize = s.size();
        if (sSize == 1 || numRows >= sSize)
            return s;
        string ans;
        vector<string> mat(numRows);
        int t = 2 * numRows - 2;
        for (int i = 0, x = 0; i < sSize; i++) {
            mat[x] += s[i];
            i% t < (numRows - 1) ? (++x) : (--x);
        }
        ans = accumulate(mat.begin(), mat.end(), string{},
            [](const string& a, const string& b)->string {return a.empty() ? b : a + b; });
        return ans;
    }
};

