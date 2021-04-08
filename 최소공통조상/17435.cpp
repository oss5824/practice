#include <iostream>
#include <cmath>
using namespace std;
int arr[21][200001], v[200001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, b; cin >> n; for (int i = 1; i <= n; i++) { cin >> v[i]; arr[0][i] = v[i]; } cin >> m;
	for (int i = 1; i <= 20; i++)for (int j = 1; j <= 200000; j++)arr[i][j] = arr[i - 1][arr[i - 1][j]];
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		while (a > 0) { int val = (int)log2(a); b = arr[val][b]; a -= pow(2, val); }
		cout << b << "\n";
	}
	return 0;
}

