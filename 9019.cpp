#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int arr[10001];
char c[5] = { 'D','S','L','R' };
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int T, a, b;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;
		queue<pair<int, string>>q;
		memset(arr, 0, sizeof(arr));
		q.push({ a, "" });
		arr[a] = 1;
		while (!q.empty())
		{
			int value = q.front().first;
			string s = q.front().second;
			q.pop();
			arr[value] = 1;
			if (value == b) { cout << s << endl; break; }
			int D = (value * 2 > 9999) ? (value * 2) % 10000 : value * 2;
			int S = (value == 0) ? 9999 : value - 1;		
			int L = (value % 1000) * 10 + (value / 1000), R = (value / 10) + (value % 10) * 1000;
			int v[4] = { D,S,L,R };
			for (int i = 0; i < 4; i++)if (!arr[v[i]]) { arr[v[i]] = 1; q.push({ v[i],s + c[i] });}
		}
	}
	return 0;
}