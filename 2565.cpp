#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n, _max = 0;
	cin >> n;
	vector<pair<int, int>>v(n);
	vector <int>s(n);
	for (int i = 0; i < n; i++)cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		s[i] = 1;
		for (int j = 0; j < i; j++)if (v[i].second > v[j].second)s[i] = max(s[i], s[j] + 1);
		_max = max(_max, s[i]);
	}
	printf("%d", n - _max);
	return 0;
}
//cin.tie(NULL);
//ios::sync_with_stdio(false);
