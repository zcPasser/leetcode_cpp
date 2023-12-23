#pragma once
#include <stack>
using namespace std;
class MyQueue {
public:
    stack<int> stdInStack;
    stack<int> stdOutStack;
    MyQueue() {

    }

    void push(int x) {
        stdInStack.push(x);
    }

    int pop() {
        if (stdOutStack.empty()) {
            while (!stdInStack.empty()) {
                stdOutStack.push(stdInStack.top());
                stdInStack.pop();
            }
        }
        int ans = stdOutStack.top();
        stdOutStack.pop();
        return ans;
    }

    int peek() {
        int ans = this->pop();
        stdOutStack.push(ans);
        return ans;
    }

    bool empty() {
        return stdInStack.empty() && stdOutStack.empty();
    }
};

