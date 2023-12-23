#pragma once
#include<string>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        vector<int> cnts(26, 0);
        for (const char& ch : s)
            cnts[ch - 'a']++;
        priority_queue<pair<int, char>> que;
        for (int i = 0; i < 26; i++)
            if (cnts[i] > 0)
                que.push({ cnts[i], i + 'a' });
        string ans;
        while (!que.empty()) {
            pair<int, char> elem = que.top();
            while (elem.first--)
                ans += elem.second;
            // ans += string(elem.first, elem.second);
            que.pop();
        }
        return ans;
    }
};
//struct cmp {
//   bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
//        return a.second < b.second;
//    }
//};
//class Solution {
//public:
//    string frequencySort(string s) {
//        vector<int> cnts(26, 0);
//        for (char ch : s)
//            cnts[ch - 'a']++;
//        priority_queue<pair<char, int>, vector<pair<char,int>>, cmp> que;
//        for (int i = 0; i < 26; i++)
//            if (cnts[i] > 0)
//                que.push(make_pair(i + 'a', cnts[i]));
//        string ans;
//        while (!que.empty()) {
 //           pair<char, int> elem = que.top();
//            ans += string(elem.second, elem.first);
//            que.pop();
//        }
//        return ans;
//    }
//};

