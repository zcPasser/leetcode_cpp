#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;
class Solution844
{
private:
    string build(string s) {
        string new_s;
        for (char ch : s) {
            if (ch != '#') {
                new_s.push_back(ch);
            }
            else if (!new_s.empty()) {
                new_s.pop_back();
            }
        }
        return new_s;
    }
public:
    bool backspaceCompare(string s, string t) {
        //return build(s) == build(t);
        int skip_s = 0, skip_t = 0;
        int i = s.size() - 1, j = t.size() - 1;
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    skip_s++;
                    i--;
                }
                else if (skip_s > 0) {
                    skip_s--;
                    i--;
                }
                else {
                    break;
                }
            }
            while (j >= 0) {
                if (t[j] == '#') {
                    skip_t++;
                    j--;
                }
                else if (skip_t > 0) {
                    skip_t--;
                    j--;
                }
                else {
                    break;
                }
            }
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
            }
            else if (i >= 0 || j >= 0) {
                return false;
            }

            i--;
            j--;
        }
        return true;
    }
};

