#pragma once
#include<string>
//Î´½â¾ö
class Solution {
public:
    bool isNumber(std::string s) {
        int sSize = s.size();
        
        int cntE = 0;
        int cntPoint = 0;
        bool hasInteger1 = false;

        for (int i = 0; i < sSize; ++i) {
            if (s[i] == '+' || s[i] == '-') {
                if (i == 0 || s[i - 1] == 'e' || s[i - 1] == 'E')
                    continue;
                else
                    return false;
            }
            else if (s[i] == '.') {
                if (cntE == 0 && cntPoint == 0 && ((i > 0 && '0' <= s[i - 1] && s[i - 1] <= '9') || (i < (sSize - 1) && '0' <= s[i + 1] && s[i + 1] <= '9'))) {
                    ++cntPoint;
                    hasInteger1 = false;
                    continue;
                }        
                else
                    return false;
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                if (cntE > 0)
                    return false;
                ++cntE;
            }
            else if ('0' <= s[i] && s[i] <= '9') {
                if (cntPoint == 0 && cntE == 0)
                    hasInteger1 = true;
                continue;
            }                
            else
                return false;
        }
        if (cntE > 0 && !hasInteger1)
            return false;
        return true;
    }
};

