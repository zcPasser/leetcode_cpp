#pragma once
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
    static int bitCnt(int n) {
        int cnt = 0;
        while (n) {
            n &= (n - 1);
            cnt++;
        }
        return cnt;
    }
    struct cmp{
        bool operator()(int a, int b) {
            int bitA = bitCnt(a);
            int bitB = bitCnt(b);
            if (bitA == bitB)
                return a < b;
            return bitA < bitB;
        }
    };
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp());
        return arr;
    }
};

