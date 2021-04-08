#include <iostream>
using namespace std;
int n, m, a, b, res;
bool M[501][501];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n >> m; while (m--) { cin >> a >> b; M[a][b] = true; }
	for (int k = 1; k <= n; k++)for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)if (M[i][k] && M[k][j])M[i][j] = true;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++) if (M[i][j] || M[j][i])cnt++;
		if (cnt == n - 1)res++;
	}cout << res;
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);