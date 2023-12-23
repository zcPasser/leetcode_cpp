#pragma once
#include<string>
#include<unordered_map>
#include<stack>
#include<cctype>
#include<queue>
using namespace std;
class Solution {
public:
    string countOfAtoms(string formula) {
        int i = 0, formulaSize = formula.size();
        auto parseAtom = [&]()->string {
            string atom;
            atom += formula[i++];
            while (i < formulaSize && islower(formula[i]))
                atom += formula[i++];
            return atom;
        };
        auto parseNum = [&]()->int {
            if (i == formulaSize || !isdigit(formula[i]))
                return 1;
            int num = 0;
            while (i < formulaSize && isdigit(formula[i]))
                num = num * 10 + int(formula[i++] - '0');
            return num;
        };
        stack<unordered_map<string, int>> stk;
        stk.push({});
        while (i < formulaSize) {
            char ch = formula[i];
            if (ch == '(') {
                i++;
                stk.push({});
            }
            else if (ch == ')') {
                i++;
                int num = parseNum();
                auto atomNum = stk.top();
                stk.pop();
                //for (auto &[atom, val] : atomNum) {
                //    stk.top()[atom] += val * num;
                //}
            }
            else {
                string atom = parseAtom();
                int num = parseNum();
                stk.top()[atom] += num;
            }
        }
        auto& atomNum = stk.top();
        priority_queue<pair<string, int>, vector<pair<string,int>>, greater<pair<string,int>>> que;
        //for (auto& [atom, val] : atomNum)
        //    que.emplace(make_pair(atom, val));
        string ans;
        while (!que.empty()) {
            auto elem = que.top();
            que.pop();
            ans += elem.first;
            if (elem.second > 1)
                ans += to_string(elem.second);
        }
        return ans;
    }
};

