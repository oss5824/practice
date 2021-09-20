#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int T, N, dp[2][1000][1000], arr[1000], sum;
int recursive(int s, int e, bool turn)
{
	if (s == e) {
		if (!turn)return dp[turn][s][e] = arr[s];
		return dp[turn][s][e] = 0;
	}
	int& val = dp[turn][s][e];
	if (val != -1)return val;
	if (!turn)return val = max(recursive(s + 1, e, 1) + arr[s],
		recursive(s, e - 1, 1) + arr[e]);
	return val = min(recursive(s + 1, e, 0), recursive(s, e - 1, 0));
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N; sum = 0; memset(dp, -1, sizeof(dp));
		for (int i = 0; i < N; i++) { cin >> arr[i]; sum += arr[i]; }
		cout << recursive(0, N - 1, 0) << "\n";
	}
}
