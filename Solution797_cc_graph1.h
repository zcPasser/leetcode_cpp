#pragma once
#include<vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(const vector<vector<int>>& graph, int begin, int target) {
        if (begin == target) {
            ans.emplace_back(path);
            return;
        }
        for (const int& node : graph[begin]) {
            path.push_back(node);
            dfs(graph, node, target);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0, graph.size() - 1);
        return ans;
    }
};

