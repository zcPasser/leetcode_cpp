#pragma once
#include<string>
using namespace std;
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int nameSize = name.size(), typedSize = typed.size();
        if (nameSize > typedSize || name[0] != typed[0])
            return false;
        int i = 0, j = 0;
        while (i < nameSize && j < typedSize) {
            if (typed[j] != name[i])
                return false;
            if ((i + 1) < nameSize && name[i] != name[i + 1]) {
                while ((j + 1) < typedSize && typed[j] == typed[j + 1])
                    j++;
            }
            i++, j++;
        }
        if (i == nameSize && j < typedSize) {
            while (j < typedSize) {
                if (typed[j] != name[i - 1])
                    return false;
                j++;
            }
        }
        if (i < nameSize && j == typedSize)
            return false;
        return true;
    }
};

