#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, a, b;
bool visit[101];
int Map[101][101];
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)if (i == j)Map[i][j] = 0; else Map[i][j] = 1e9;
	for (int i = 0; i < M; i++) { cin >> a >> b; Map[a][b] = 1; Map[b][a] = 1; }
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)if (Map[i][k] + Map[k][j] < Map[i][j])Map[i][j] = Map[i][k] + Map[k][j];
	vector<int>v;
	for (int i = 1; i <= N; i++){
		if (visit[i])continue;
		vector<int>vec;
		for (int j = 1; j <= N; j++) if (Map[i][j] != 1e9) { vec.push_back(j); visit[j] = true; }
		int len = vec.size(), distance = 1e9, idx = 0;
		for (int j = 0; j < len; j++) {
			int dist = -1;
			for (int k = 0; k < len; k++)dist = max(dist, Map[vec[j]][vec[k]]);
			if (distance > dist) { distance = dist; idx = vec[j]; }
		}
		v.push_back(idx);
	}cout << v.size(); sort(v.begin(), v.end()); for (int i : v)cout << "\n" << i;
	return 0;
}
