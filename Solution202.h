#pragma once
#include <unordered_set>
using namespace std;
class Solution202
{
private:
    int get_next(int n) {
        int new_n = 0;
        while (n > 0) {
            int tmp = (n % 10);
            new_n += tmp * tmp;
            n /= 10;
        }
        return new_n;
    }
public:
    bool isHappy(int n) {
        if (n == 1)
            return true;
        //unordered_set<int> buffer;
        int slow = n;
        int fast = this->get_next(n);
        while (fast != 1 && fast != slow) {
            slow = this->get_next(slow);
            fast = this->get_next(this->get_next(fast));
        }
        return fast == 1;
    }
};

