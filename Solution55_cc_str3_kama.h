#pragma once
#include<string>
#include<iostream>

using namespace std;
void reverseStr(string& s, int left, int right)
{
    while (left <= right)
    {
        swap(s[left++], s[right--]);
    }
    return;
}
int kama55()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int sSize = s.size(); //获取长度
    reverseStr(s, 0, sSize - 1);
    reverseStr(s, 0, n - 1);
    reverseStr(s, n, sSize - 1);
	return 0;
}
