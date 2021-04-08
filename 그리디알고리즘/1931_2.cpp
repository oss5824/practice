#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int>a, pair<int, int>b)
{
	if (a.second < b.second)return true;
	else if (a.second == b.second)
	{
		if (a.first <= b.first)return true;
		else return false;
	}
	else return false;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, result = 1; cin >> n; vector<pair<int, int>>v(n, { 0,0 });
	for (int i = 0; i < n; i++)cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end(), cmp);
	int e = v[0].second;
	for (int i = 1; i < n; i++)
	{
		if (e <= v[i].first) { result++; e = v[i].second; }
	}
	cout << result;
	return 0;
}