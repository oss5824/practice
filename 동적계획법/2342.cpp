#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000], dp[5][5][100000], score[5][5];
int recursive(int l, int r, int n)
{
	if (!arr[n])return 0;
	int& val = dp[l][r][n];
	if (val)return val;
	return val = min(recursive(arr[n], r, n + 1) + score[l][arr[n]],
		recursive(l, arr[n], n + 1) + score[r][arr[n]]);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	for (int i = 0;; i++) {
		cin >> arr[i]; if (!arr[i])break;
	}
	for (int i = 0; i < 5; i++) {
		score[0][i] = 2;
		score[1][i] = i == 3 ? 4 : 3;
		score[2][i] = i == 4 ? 4 : 3;
		score[3][i] = i == 1 ? 4 : 3;
		score[4][i] = i == 2 ? 4 : 3;
	}for (int i = 1; i <= 4; i++)score[i][i] = 1;
	cout << recursive(0, 0, 0);
}
