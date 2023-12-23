#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    static const int N = 1010;
    int father[N];
    int n;
    void init() {
        for (int i = 1; i <= n; ++i)
            father[i] = i;
    }
    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)return;
        father[v] = u;
    }
    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
    vector<int> getRemoveEdge(const vector<vector<int>>& edges) {
        init();
        for (int i = 0; i < n; ++i) {
            if (same(edges[i][0], edges[i][1]))
                return edges[i];
            join(edges[i][0], edges[i][1]);
        }
        return {};
    }
    bool isTreeAfterRemoveEdge(const vector<vector<int>>& edges, int deleteEdge) {
        init();
        for (int i = 0; i < n; ++i) {
            if (i == deleteEdge)
                continue;
            if (same(edges[i][0], edges[i][1]))
                return false;
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int inDegree[N] = { 0 };
        n = edges.size();
        for (int i = 0; i < n; ++i)
            inDegree[edges[i][1]]++;
        vector<int> vec;
        for (int i = n - 1; i >= 0; --i)
            if (inDegree[edges[i][1]] == 2)
                vec.push_back(i);
        if (vec.size() > 0) {
            if (isTreeAfterRemoveEdge(edges, vec[0]))
                return edges[vec[0]];
            else return edges[vec[1]];
        }
        return getRemoveEdge(edges);
    }
};

