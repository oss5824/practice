#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int N, M, a, b, dp[1000001][2];
vector<int>v[1000001];
int rec(bool turn, int cur,int pre)
{
	int& ret = dp[cur][turn];
	if (ret != -1)return ret; ret = 0;
	for (int next : v[cur]) {
		if (pre != next) {
			int val = rec(1, next, cur) + 1;
			if (turn)val = min(val, rec(0, next, cur));
			ret += val;
		}
	}return ret;
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; M = N - 1; memset(dp, -1, sizeof(dp));
	while (M--) { cin >> a >> b; v[a].push_back(b); v[b].push_back(a); }
	cout << min(rec(0, 1, 0), rec(1, 1, 0) + 1);
}