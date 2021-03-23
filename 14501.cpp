#include <iostream>
#include <algorithm>
using namespace std;
int n, M[17];
pair<int, int>p[17];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); int res = 0;
	cin >> n; for (int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;
	for (int i = 1; i <= n; i++)
	{
		if (i + p[i].first <= n + 1)
			M[i + p[i].first] = max(M[i + p[i].first], M[i] + p[i].second);
		M[i + 1] = max(M[i + 1], M[i]);
	}cout << M[n + 1];
	return 0;
}

