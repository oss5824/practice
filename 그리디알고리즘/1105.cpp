#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
string s, s1;
int r;
int main()
{
	cin >> s >> s1;
	while (s.size() != s1.size())s = '0' + s;
	for (int i = 0; i < s.size(); i++) { if (s[i] == '8' && s1[i] == '8')r++; else if (s[i] != s1[i]) break; }
	cout << r;
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);


