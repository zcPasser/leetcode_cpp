#pragma once
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> uose(wordList.begin(), wordList.end());
        if (uose.find(endWord) == uose.end())
            return 0;
        unordered_map<string, int> uomp;
        queue<string> que;
        que.push(beginWord);
        uomp.insert(pair<string, int>(beginWord, 1));
        int wordSize = beginWord.size();
        while (!que.empty()) {
            string word = que.front();
            que.pop();
            int path = uomp[word];
            for (int i = 0; i < wordSize; ++i) {
                string newWord = word;
                for (int j = 0; j < 26; ++j) {
                    newWord[i] = j + 'a';
                    if (newWord == endWord)
                        return path + 1;
                    if (uose.find(newWord) != uose.end() && uomp.find(newWord) == uomp.end()) {
                        uomp.insert(pair<string, int>(newWord, path + 1));
                        que.push(newWord);
                    }
                }
            }
        }
        return 0;
    }
};

