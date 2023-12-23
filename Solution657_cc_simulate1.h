#pragma once
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (const char& ch : moves)
            if (ch == 'U')
                y++;
            else if (ch == 'D')
                y--;
            else if (ch == 'L')
                x--;
            else
                x++;
        return x == 0 && y == 0;
    }
};

