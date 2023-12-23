#pragma once
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> indices;
        int xMin = INT_MAX, xMax = INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (const int& x : nums[i]) {
                indices[x].push_back(i);
                xMin = min(xMin, x);
                xMax = max(xMax, x);
            }
        }
        vector<int> freq(n);
        int inside = 0;
        int left = xMin, right = xMin - 1;
        int bestLeft = xMin, bestRight = xMax;
        while (right < xMax) {
            ++right;
            if (indices.find(right) != indices.end()) {
                for (const int& x : indices[right]) {
                    ++freq[x];
                    //inside ��¼�Ƿ�n���б� ȫ�������ݡ�
                    if (freq[x] == 1)
                        ++inside;
                }
                while (inside == n) {
                    if (right - left < bestRight - bestLeft) {
                        bestLeft = left;
                        bestRight = right;
                    }
                    if (indices.find(left) != indices.end()) {
                        for (const int& x : indices[left]) {
                            --freq[x];
                            if (freq[x] == 0)
                                --inside;
                        }
                    }
                    ++left;
                }
            }
        }
        return { bestLeft, bestRight };
    }
};

