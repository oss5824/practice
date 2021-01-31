#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
vector <pair<long double, pair<int, int>>>d;
map<pair<int, int>, long double>dist;
int level[1001];
int arr[1001];
long double result;
int search(int num)
{
	if (num == arr[num])return num;
	else return arr[num] = search(arr[num]);
}
int add(pair<long double, pair<int, int>>v)
{
	int a = v.second.first, b = v.second.second, x = search(a), y = search(b);
	long double c = v.first;
	if (x == y)return 1;
	if (level[x] > level[y]) { int tmp = x; x = y; y = tmp; }
	arr[x] = y; result += c;
	if (level[x] == level[y])level[y]++;
	return 0;
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<pair<int, int>>v;
	long double f; v.push_back({ 0,0 });
	for (int i = 0; i < n; i++) { int a, b; cin >> a >> b; v.push_back({ a,b }); }
	for (int i = 0; i < m; i++) { int a, b; cin >> a >> b; dist[make_pair(a, b)] = -1; }
	int len = v.size();
	for (int i = 1; i < len; i++)
	{
		arr[i] = i;
		for (int j = i + 1; j < len; j++)
		{
			long double a;
			a = (dist[make_pair(i, j)] != -1) ?
				sqrt(powl((v[i].first - v[j].first), 2) + pow((v[i].second - v[j].second), 2)) : 0;
			d.push_back({ a, { i,j } });
		}
	}
	sort(d.begin(), d.end());
	len = d.size();
	for (int i = 0; i < len; i++)add(d[i]);
	printf("%.2lf", result);
	return 0;
}