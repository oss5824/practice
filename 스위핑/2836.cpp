#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1e9
vector<pair<int, int>>arr;
typedef long long ll;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m; cin >> n >> m; arr.assign(n, { 0,0 });
	for (int i = 0; i < n; i++)cin >> arr[i].first >> arr[i].second;
	stable_sort(arr.begin(), arr.end(), greater<pair<int, int>>());
	int s = -INF, e = -INF; ll result = m;
	for (int i = 0; i < n; i++)
	{
		int ns = arr[i].first, ne = arr[i].second;
		if (ns <= ne)continue;
		if (s == -INF && e == -INF) { s = ns; e = ne; continue; }
		if (e <= ns) e = min(ne, e);
		else { result += (ll)2 * ((ll)(s - e)); s = ns; e = ne; }
	}
	if (s > e)result += (ll)2 * ((ll)(s - e));
	cout << result << "\n";
	return 0;
}
