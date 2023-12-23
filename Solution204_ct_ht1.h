#pragma once
#include<bitset>
class Solution {
public:
    int countPrimes(int n) {
        using namespace std;
        if (n < 2)
            return 0;
        bitset<5000000> isPrime;
        isPrime.set();
        isPrime[0] = 0, isPrime[1] = 0;
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ++ans;
                if ((long long)i * i < n)
                    for (int j = i * i; j < n; j += i)
                        isPrime[j] = 0;
            }
        }
        return ans;
    }
};

