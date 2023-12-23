#pragma once
#include<queue>
using namespace std;
class MyStack {
public:
    queue<int> que1;
    queue<int> que2;
    MyStack() {

    }

    void push(int x) {
        this->que1.push(x);
    }

    int pop() {
        int size = que1.size();
        while (size > 1) {
            this->que2.push(this->que1.front());
            this->que1.pop();
            size--;
        }
        int ans = que1.front();
        que1.pop();
        while (!que2.empty()) {
            que1.push(que2.front());
            que2.pop();
        }
        return ans;
    }

    int top() {
        return que1.back();
    }

    bool empty() {
        return que1.empty();
    }
};
