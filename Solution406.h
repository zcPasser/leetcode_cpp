#pragma once
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> que;
        for (const auto& man : people) {
            int pos = man[1];
            list<vector<int>>::iterator it = que.begin();
            while (pos--) {
                it++;
            }
            que.insert(it, man);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};

