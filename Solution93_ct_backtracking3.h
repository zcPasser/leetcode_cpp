#pragma once
#include <vector>
#include <string>
#include <numeric>
using namespace std;

class Solution {
private:
    vector<string> ans;

    bool isLegal(const string& s, int start, int end)
    {
        int addrSize = end - start + 1;
        if (addrSize == 1)
            return true;
        else if (addrSize > 1)
        {
            if (s[start] == '0')
                return false;
            int val = 0;
            for (int i = start; i <= end; i++)
            {
                if (s[i] < '0' || s[i] > '9')
                    return false;
                val = val * 10 + (s[i] - '0');
                if (val > 255)
                    return false;
            }
                
        }
        return true;
    }

    void backtracking(const string& s, int start, const int& sSize, vector<string>& path)
    {
        if (path.size() == 3 && start < sSize)
        {
            string ss = s.substr(start, sSize - start);
            if (isLegal(s, start, sSize - 1))
            {
                ans.push_back(path[0] + "." + path[1] + "." + path[2] + "." + ss);
            }
            return;
        }
        // ¼ôÖ¦
        for (int i = start; i < sSize && isLegal(s, start, i); i++)
        {
            path.push_back(s.substr(start, i - start + 1));
            backtracking(s, i + 1, sSize, path);
            path.pop_back();

        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int sSize = s.size();
        if (sSize < 4)
            return {};
        vector<string> path;
        backtracking(s, 0, sSize, path);
        return ans;
    }
};

