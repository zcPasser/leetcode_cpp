#include<string>
using namespace std;
class Solution {
public:
    int balancedStringSplit(string s) {
        int sSize = s.size();
        int ans = 0;
        for (int i = 0; i < sSize;) {
            int j = i + 1;
            int score = s[i] == 'L' ? 1 : -1;
            while (j < sSize && score != 0)
                score += s[j++] == 'L' ? 1 : -1;
            i = j;
            ans++;
        }
        return ans;
    }
};