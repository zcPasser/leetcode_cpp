#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    //int  n = 200001;
    vector<int> father;
    void init(int n) {
        father.resize(n, 0);
        for (int i = 0; i < n; ++i)
            father[i] = i;
    }
    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)return;
        father[v] = u;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //father.resize(n, 0);
        init(n);
        for (const auto& edge : edges)
            join(edge[0], edge[1]);
        return isSame(source, destination);
    }
};

