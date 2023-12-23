#pragma once
#include<string>
using namespace std;
class Solution {
private:
    int str2int(const string& str, int left, int right)
    {
        if (left > right)
            return 0;
        int ans = 0;
        for (int i = left; i <= right; i++)
            ans = ans * 10 + (str[i] - '0');
        return ans;
    }
public:
    int compareVersion(string version1, string version2) {
        int v1Size = version1.size(), v2Size = version2.size();
        int l1 = -1, r1 = 0, l2 = -1, r2 = 0;
        while (r1 < v1Size || r2 < v2Size)
        {
            int val1 = 0, val2 = 0;
            if (r1 < v1Size)
            {
                while (r1 < v1Size && version1[r1] != '.')
                    r1++;
                val1 = this->str2int(version1, l1 + 1, r1 - 1);
                l1 = r1;
                r1++;
            }

            if (r2 < v2Size)
            {
                while (r2 < v2Size && version2[r2] != '.')
                    r2++;
                val2 = this->str2int(version2, l2 + 1, r2 - 1);
                l2 = r2;
                r2++;
            }


            if (val1 == val2)
                continue;
            return val1 < val2 ? -1 : 1;
        }

        return 0;
    }
};

