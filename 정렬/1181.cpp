#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;
bool str_cmp(pair<char*, int>& a, pair<char*, int>& b)
{
	if (a.second < b.second)return true;
	else if (a.second == b.second)
	{
		if (strcmp(a.first, b.first) < 0)return true;
		else if (strcmp(a.first, b.first) > 0)return false;
	}
	else return false;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	vector<pair<char*, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		v[i].first = new char[51];
		cin >> v[i].first;
		v[i].second = strlen(v[i].first);
	}
	sort(v.begin(), v.end(), str_cmp);
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1 && !strcmp(v[i].first, v[i + 1].first))continue;
		printf("%s\n", v[i].first);
	}
	return 0;
}