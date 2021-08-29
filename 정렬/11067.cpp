#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T, N, M;
pair<int, int>res[100001];
vector<int>v[100001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N;
		int bef = 0, n = 1;
		for (int i = 0, a, b; i < N; i++) { cin >> a >> b; v[a].push_back(b); }
		for (int i = 0; n <= N; i++) {
			int sz = v[i].size();
			if (!sz)continue;
			sort(v[i].begin(), v[i].end());
			if (v[i][0] == bef)for (int j = 0; j < sz; j++, n++) res[n] = { i,v[i][j] };
			else for (int j = sz - 1; j >= 0; j--, n++) res[n] = { i,v[i][j] };
			bef = (v[i][0] == bef) ? v[i][sz - 1] : v[i][0];
			v[i].clear();
		}
		cin >> M;
		while (M--) { cin >> N; cout << res[N].first << " " << res[N].second << "\n"; }
	}	
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
