#pragma once
#include <vector>
#include <string>
#include <queue>
using namespace std;
class Solution {
private:
    struct node
    {
        string _path;
        int _leftCnt, _rightCnt;
        node(string path, int leftCnt, int rightCnt)
        {
            _path = path;
            _leftCnt = leftCnt;
            _rightCnt = rightCnt;
        }
    };
public:
    vector<string> generateParenthesis(int n) {
        if (n == 1)
            return { "()" };
        vector<string> ans;
        queue<node> queNode;
        
        queNode.push(node("", 0, 0));
        while (!queNode.empty())
        {
            int levelSize = queNode.size();
            for (int i = 0; i < levelSize; i++)
            {
                node nod = queNode.front();
                queNode.pop();
                if (nod._leftCnt == nod._rightCnt && nod._leftCnt == n)
                {
                    ans.push_back(nod._path);
                    continue;
                }
                if (nod._leftCnt < n)
                {
                    //nod._path = nod._path + "(";
                    //nod._leftCnt += 1;
                    queNode.push(node(nod._path + "(", nod._leftCnt + 1, nod._rightCnt));
                }
                if (nod._leftCnt > nod._rightCnt)
                {
                    nod._path = nod._path + ")";
                    nod._rightCnt += 1;
                    queNode.push(nod);
                }
            }
        }

        return ans;
    }
};

