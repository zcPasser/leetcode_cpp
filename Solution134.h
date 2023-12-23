#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int fuelTankCapacity = 0;
        int curSum = 0;
        int gasSize = gas.size();
        int begin = 0;
        for (int i = 0; i < gasSize; i++) {
            fuelTankCapacity += gas[i] - cost[i];
            curSum += gas[i] - cost[i];
            if (curSum < 0) {
                begin = i + 1;
                curSum = 0;
            }
        }
        if (fuelTankCapacity < 0)
            return -1;
        return begin;
    }
};

