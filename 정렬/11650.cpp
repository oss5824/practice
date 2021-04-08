#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool sec_compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first < b.first)return true;
	else if (a.first == b.first)
	{
		if (a.second < b.second)return true;
		else return false;
	}
	else return false;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	vector<pair<int, int>>v(n);
	for (int i = 0; i < n; i++)cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end(), sec_compare);
	for (int i = 0; i < n; i++)printf("%d %d\n", v[i].first, v[i].second);
	return 0;
}