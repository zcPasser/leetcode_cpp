#pragma once
#include<iostream>
#include<string>
using namespace std;
int f()
{
	string s;
	while (cin >> s)
	{
		int cnt = 0;
		int sOldSize = s.size();
		for (char ch : s)
			if (ch >= '0' && ch <= '9')
				cnt++;
		int sNewSize = sOldSize + cnt * 5;
		s.resize(sNewSize);
		for (int p1 = sNewSize - 1, p2 = sOldSize - 1; p1 > p2; --p1, --p2)
		{
			if (s[p2] < '0' || s[p2]>'9')
				s[p1] = s[p2];
			else
			{
				s[p1] = 'r';
				s[p1 - 1] = 'e';
				s[p1 - 2] = 'b';
				s[p1 - 3] = 'm';
				s[p1 - 4] = 'u';
				s[p1 - 5] = 'n';
				p1 -= 5;
			}
		}
		cout << s << endl;
	}
	return 0;
}

