#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, M, result;
bool visit[10001];
vector<int>v[10001];
vector<int>res;
int bfs(int x)
{
	queue<int>q; q.push(x); int cnt = 1;
	memset(visit, false, sizeof(visit)); visit[x] = true;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int next: v[cur]) {
			if (visit[next])continue;
			q.push(next); visit[next] = true; cnt++;
		}
	}
	return cnt;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) { int a, b; cin >> a >> b;  v[b].push_back(a); }
	for (int i = 1; i <= N; i++)
	{
		int value = bfs(i);
		if (result == 0) { result = value; res.push_back(i); }
		else if (result == value) res.push_back(i);
		else if (result < value) { res.clear(); result = value; res.push_back(i); }
	}
	for (int i : res)cout << i << " ";
	return 0;
}

