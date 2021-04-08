#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;
int n, m, arr[101], M[10001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); int res = 0;
	cin >> n >> m; fill(M, M + 10001, INF);
	for (int i = 1; i <= n; i++)cin >> arr[i];
	M[0] = 0;
	for (int i = 1; i <= n; i++)for (int j = arr[i]; j <= m; j++)M[j] = min(M[j], M[j - arr[i]] + 1);
	(M[m] == INF) ? cout << "-1" : cout << M[m];
	return 0;
}

