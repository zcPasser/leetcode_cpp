#pragma once
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>>idx;
    vector<int>nums;
public:
    RandomizedCollection() {

    }

    bool insert(int val) {
        nums.push_back(val);
        idx[val].insert(nums.size() - 1);
        return idx[val].size() == 1;
    }

    bool remove(int val) {
        if (idx.count(val) == 0)
            return false;
        int i = *(idx[val].begin());
        nums[i] = nums.back();
        idx[val].erase(i);
        idx[nums[i]].erase(nums.size() - 1);
        if (i < nums.size() - 1)
            idx[nums[i]].insert(i);
        if (idx[val].size() == 0)
            idx.erase(val);
        nums.pop_back();
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

