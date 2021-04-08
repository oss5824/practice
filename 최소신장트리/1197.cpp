#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T, n, m;
int arr[10001], level[10001];
int result;
vector<pair<int, pair<int, int>>>v;
int search(int num) { if (num == arr[num])return num; else return arr[num] = search(arr[num]); }
int add(int a, int b, int c)
{
	int x = search(a), y = search(b);
	if (x == y)return 1;
	if (x > y) { int tmp = x; x = y; y = tmp; }
	arr[x] = y; result += c;
	if (level[x] == level[y])level[y]++;
	return 0;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(c, make_pair(a, b)));
		arr[a] = a; arr[b] = b; level[a] = 1; level[b] = 1;
	}
	sort(v.begin(), v.end());
	int len = v.size();
	for (int i = 0; i < len; i++)add(v[i].second.first, v[i].second.second, v[i].first);
	cout << result;
	return 0;
}