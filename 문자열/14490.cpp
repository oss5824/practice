#include<iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define INF 
using namespace std;
int gcd(int a, int b)
{
	if (a < b)swap(a, b);
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	string s; cin >> s; int len = s.length();
	string n, m; bool check = false;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ':') { check = true; continue; }
		if (!check)n += s[i]; else m += s[i];
	}
	int N = stoi(n), M = stoi(m), value = gcd(N, M);
	cout << N / value << ":" << M / value;
	return 0;
}