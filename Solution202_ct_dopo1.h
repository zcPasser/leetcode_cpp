#pragma once
using namespace std;
class Solution {
private:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int a = n % 10;
            n /= 10;
            sum += a * a;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        if (n == 1)
            return true;
        int slow = n, fast = getNext(n);
        int sum = 0;
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
};

