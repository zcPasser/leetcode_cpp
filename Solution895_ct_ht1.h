#pragma once
#include<stack>
#include<unordered_map>
using namespace std;
class FreqStack {
private:
    unordered_map<int, int>cnt;
    unordered_map<int, stack<int>>group;
    int maxCnt;
public:
    FreqStack() {
        maxCnt = 0;
    }

    void push(int val) {
        ++cnt[val];
        group[cnt[val]].push(val);
        maxCnt = max(maxCnt, cnt[val]);
    }

    int pop() {
        int val = group[maxCnt].top();
        --cnt[val];
        group[maxCnt].pop();
        if (group[maxCnt].empty())
            --maxCnt;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

