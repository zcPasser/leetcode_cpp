#pragma once
#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution904
{
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0, end = 0;
        unordered_map<int, int> cnt;
        int len_fruits = fruits.size();
        int ans = 0;
        while (end < len_fruits) {
            cnt[fruits[end]]++;
            while (cnt.size() > 2) {
                auto it = cnt.find(fruits[start]);
                (it->second)--;
                if ((it->second) == 0) {
                    cnt.erase(it);
                }
                start++;
            }
            ans = max(ans, end - start + 1);
            end++;
        }
        return ans;
    }
};

