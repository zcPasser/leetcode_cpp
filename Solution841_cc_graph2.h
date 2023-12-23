#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    vector<bool> visited;
    void dfs(const vector<vector<int>>& rooms, int key) {
        visited[key] = true;
        for (int k : rooms[key]) {
            if (!visited[k]) {
                dfs(rooms, k);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited.resize(rooms.size(), false);
        dfs(rooms, 0);
        for (bool v : visited)
            if (!v)
                return false;
        return true;
    }
};


