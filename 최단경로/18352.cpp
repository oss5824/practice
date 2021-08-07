#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N, M, K, X, d[300001];
vector<int>v[300001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> K >> X;
	while (M--) { int a, b; cin >> a >> b; v[a].push_back(b); }
	fill(d, d + N + 1, 1e9);
	d[X] = 0; priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	q.push({ 0,X });
	while (!q.empty()) {
		int curD = q.top().first, curX = q.top().second; q.pop();
		if (d[curX] < curD)continue;
		for (int nextX : v[curX]) {
			int nextD = curD + 1;
			if (nextD < d[nextX]) { q.push({ nextD,nextX }); d[nextX] = nextD; }
		}
	}
	bool check = false;
	for (int i = 1; i <= N; i++)if (d[i] == K) { cout << i << "\n"; check = true; }
	if (!check)cout << "-1";
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);