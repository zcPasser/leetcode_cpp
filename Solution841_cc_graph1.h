#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    void dfs(const vector<vector<int>>& rooms, int key, vector<bool>& visited) {
        if (visited[key])
            return;
        visited[key] = true;
        for (const int& k : rooms[key]) {
            dfs(rooms, k, visited);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int roomsSize = rooms.size();
        vector<bool> visited(roomsSize, false);
        //visited[0] = true;
        dfs(rooms, 0, visited);
        for (bool v : visited)
            if (!v)
                return false;
        return true;
    }
};

