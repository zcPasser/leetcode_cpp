#pragma once
#include<string>
#include<unordered_map>
class Solution {
public:
    std::string fractionToDecimal(int numerator, int denominator) {
        using namespace std;
        long n = numerator, d = denominator;
        if (n % d == 0)
            return to_string(n / d);
        string ans;
        if (n < 0 || d < 0) {
            n = abs(n), d = abs(d);
            ans.push_back('-');
        }
        ans += to_string(n / d) + ".";
        n %= d;
        int ansSize = ans.size();
        unordered_map<int, int> up;
        while (n && !up.count(n)) {
            up[n] = ansSize++;
            n *= 10;
            ans.push_back('0' + n / d);
            n %= d;
        }
        if (n)
            ans = ans.substr(0, up[n]) + '(' + ans.substr(up[n]) + ')';

        return ans;
    }
};

