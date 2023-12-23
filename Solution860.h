#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        int billsSize = bills.size();
        for (int i = 0; i < billsSize; i++) {
            if (bills[i] == 5)
                five++;
            else if (bills[i] == 10) {
                if (five == 0)
                    return false;
                five--;
                ten++;
            }
            else {
                twenty++;
                if (five >= 1 && ten >= 1) {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                    five -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};

