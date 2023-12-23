#pragma once
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSe(wordList.begin(), wordList.end());
        if (wordSe.find(endWord) == wordSe.end())
            return 0;
        unordered_map<string, int> visitMp;
        visitMp[beginWord] = 1;
        queue<string> que;
        que.push(beginWord);
        while (!que.empty()) {
            string word = que.front();
            que.pop();
            int path = visitMp[word];
            for (int i = 0; i < word.size(); ++i) {
                string newWord = word;
                for (int j = 0; j < 26; ++j) {
                    newWord[i] = 'a' + j;
                    if (newWord == endWord)
                        return path + 1;
                    if (wordSe.find(newWord) != wordSe.end() && visitMp.find(newWord) == visitMp.end()) {
                        visitMp.insert(pair<string, int>(newWord, path + 1));
                        que.push(newWord);
                    }
                }
            }
        }
        return 0;
    }
};


