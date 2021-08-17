#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<cmath>
#define R 1000000000
using namespace std;
int n;
map<int, int>m; 
void print()
{
	if (m[n] > 0)cout << "1\n"; else if (m[n] < 0)cout << "-1\n"; else cout << "0\n"; cout << abs(m[n]);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	m[0] = 0; m[1] = 1; cin >> n;
	if (n > 0) { int s = 2; while (s <= n) { m[s] = (m[s - 2] + m[s - 1]) % R; s++; } }
	else if (n < 0) { int s = -1; while (n <= s) { m[s] = (m[s + 2] - m[s + 1]) % R; s--; } }
	print();
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);