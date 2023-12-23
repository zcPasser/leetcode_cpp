#pragma once
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int skipS = 0, skipT = 0;
        int idxS = s.size() - 1, idxT = t.size() - 1;
        while (idxS >= 0 || idxT >= 0) {
            while (idxS >= 0) {
                if (s[idxS] == '#')
                    skipS++, idxS--;
                else if (skipS > 0)
                    skipS--, idxS--;
                else
                    break;
            }
            while (idxT >= 0) {
                if (t[idxT] == '#')
                    skipT++, idxT--;
                else if (skipT > 0)
                    skipT--, idxT--;
                else
                    break;
            }
            if (idxS >= 0 && idxT >= 0) {
                if (s[idxS] != t[idxT])
                    return false;
            }
            else if (idxS >= 0 || idxT >= 0)
                return false;
            idxS--, idxT--;
        }
        return true;
    }
};

