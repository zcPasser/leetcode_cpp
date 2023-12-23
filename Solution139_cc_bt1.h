#pragma once
#include<vector>
#include<string>
#include<unordered_set>
class Solution {
private:
    bool backtracking(const std::string& s, const std::unordered_set<std::string>& wordSet, std::vector<bool>& memory, int startIdx) {
        //using namespace std;
        if (startIdx >= s.size())
            return true;
        //使用memory数组保存每次计算的以startIndex起始的计算结果，如果memory[startIndex]里已经被赋值了，直接用memory[startIndex]的结果。
        if (!memory[startIdx])
            return memory[startIdx];
        for (int i = startIdx; i < s.size(); ++i) {
            std::string word = s.substr(startIdx, i - startIdx + 1);
            if (wordSet.find(word) != wordSet.end() && backtracking(s, wordSet, memory, i + 1))
                return true;
        }
        memory[startIdx] = false;
        return false;
    }
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        using namespace std;
        int wordDictSize = wordDict.size(), sSize = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> memory(sSize, true);
        
        return backtracking(s, wordSet, memory, 0);
    }
};

