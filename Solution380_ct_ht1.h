#pragma once
#include<vector>
#include<unordered_map>
class RandomizedSet {
private:
    std::vector<int> data;
    std::unordered_map<int, int> indices;
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if (indices.find(val) != indices.end())
            return false;
        data.push_back(val);
        indices[val] = data.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (indices.find(val) == indices.end())
            return false;
        int idx = indices[val];
        data[idx] = data.back();
        data.pop_back();
        indices[data[idx]] = idx;
        indices.erase(val);
        return true;
    }

    int getRandom() {
        return data[rand() % data.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */