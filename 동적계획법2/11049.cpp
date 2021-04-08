#include<iostream>
#include<algorithm>
#define INF 10e9
using namespace std;
int n, a, b, d[501], dp[501][501];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n; for (int i = 1; i <= n; i++) { cin >> a >> b; if (i == 1)d[0] = a; d[i] = b; }
	for (int diag = 1; diag <= n - 1; diag++)
		for (int i = 1; i <= n - diag; i++)
		{
			int j = diag + i;
			dp[i][j] = INF;
			for (int k = i; k <= j - 1; k++)dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + d[i - 1] * d[k] * d[j]);
		}
	cout << dp[1][n];
	return 0;
}