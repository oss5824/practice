#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
int arr[300000];
pair<int, int>p[300000];
map<string, int>m;
int search(int num)
{
	if (num == arr[num])return num;
	else
	{
		arr[num] = search(arr[num]);
		return arr[num];
	}
}
int add(int a, int b)
{
	int x = search(a), y = search(b);
	if (x == y)return 0;
	if (p[x].first > p[y].first) { int tmp = x; x = y; y = tmp; }
	arr[x] = y; p[y].second = p[x].second + p[y].second;
	if (p[x].first == p[y].first)p[y].first++;
	return 1;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int T, n, a;
	cin >> T;
	for (int q = 0; q < T; q++)
	{
		cin >> n;
		int count = 1; 
		memset(arr, 0, sizeof(arr));
		m.clear();
		memset(p, 0, sizeof(p));
		for (int i = 0; i < n; i++)
		{
			string a, b;
			cin >> a >> b;
			if (m[a] == 0) { m[a] = count; arr[count] = count; p[count].first = 1; p[count].second = 1; count++; }
			if (m[b] == 0) { m[b] = count; arr[count] = count; p[count].first = 1; p[count].second = 1; count++; }
			add(m[a], m[b]);
			int val = search(m[a]);
			cout << p[val].second << "\n";
		}
	}
	return 0;
}