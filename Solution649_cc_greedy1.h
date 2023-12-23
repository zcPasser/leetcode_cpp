#pragma once
#include<string>
#include<queue>
using namespace std;
class Solution {
public:
    string predictPartyVictory(string senate) {
        int senateSize = senate.size();
        queue<int> radiantQue, direQue;
        for (int i = 0; i < senateSize; ++i)
            if (senate[i] == 'R')
                radiantQue.push(i);
            else
                direQue.push(i);
        while (!radiantQue.empty() && !direQue.empty()) {
            int idx1 = radiantQue.front(), idx2 = direQue.front();
            // idx1 + senateSize : 下一回合
            if (idx1 < idx2)
                radiantQue.push(idx1 + senateSize);
            else
                direQue.push(idx2 + senateSize);
            radiantQue.pop();
            direQue.pop();
        }
        return radiantQue.empty() ? "Dire" : "Radiant";
    }
};

