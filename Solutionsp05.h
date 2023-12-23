#pragma once
#include<string>
using namespace std;
class Solutionsp05
{
public:
    string replaceSpace(string s) {
        int len_s = s.size();
        int cnt = 0;
        for (char ch : s) {
            if (ch == ' ')
                cnt++;
        }
        s.resize(len_s + cnt * 2);
        for (int new_idx = s.size() - 1, old_idx = len_s - 1; old_idx > -1; old_idx--) {
            if (s[old_idx] != ' ') {
                s[new_idx] = s[old_idx];
                new_idx--;
            }
            else {
                s[new_idx] = '0';
                new_idx--;
                s[new_idx] = '2';
                new_idx--;
                s[new_idx] = '%';
                new_idx--;
            }
        }
        return s;
    }
};

