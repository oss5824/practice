#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, M;
bool visit[1001];
vector<int>v[1001];
void bfs(int x)
{
	queue<int>q; q.push(x); visit[x] = true;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int next : v[cur])
		{
			if (visit[next])continue;
			q.push(next); visit[next] = true;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> M;
	while (M--) {
		cin >> N; memset(visit, false, sizeof(visit)); int cnt = 0;
		for (int i = 1; i <= N; i++) { int a; cin >> a; v[i].push_back(a); }
		for (int i = 1; i <= N; i++)if (!visit[i]) { bfs(i); cnt++; }
		for (int i = 1; i <= N; i++)v[i].clear();
		cout << cnt << "\n";
	}
	return 0;
}


