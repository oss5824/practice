#include <iostream>
#include <vector>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, T, a, b;
	cin >> n;
	int* arr = new int[n + 1];
	for (int i = 1; i <= n; i++)cin >> arr[i];
	int** M = new int* [n + 1];
	for (int i = 0; i <= n; i++)M[i] = new int[n + 1];
	for (int i = 1; i <= n; i++)for (int j = i; j <= n; j++)M[i][j] = (i == j) ? 1 : 0;
	for (int i = 1; i < n; i++) if (arr[i] == arr[i + 1])M[i][i + 1] = 1;
	for (int len = 3; len <= n; len++)
		for (int start = 1; start <= n - len + 1; start++)
		{
			int end = len + start - 1;
			if (arr[start] == arr[end] && M[start + 1][end - 1])M[start][end] = 1;
		}
	cin >> T;
	vector<pair<int, int>>v(T);
	for (int i = 0; i < T; i++)cin >> v[i].first >> v[i].second;
	for (int i = 0; i < T; i++)printf("%d\n", M[v[i].first][v[i].second]);
}
