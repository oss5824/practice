#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#include<utility>
#define INF 1000000001
using namespace std;
int N, M, result, s, e;
vector<pair<int, int>>v[10001];
bool visit[10001];
bool bfs(int num)
{
	queue<int>q; q.push(s); memset(visit,false, sizeof(visit)); visit[s] = true;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (cur == e) { return true; }
		for (pair<int, int>p : v[cur]) {
			int next = p.first, nextD = p.second;
			if (p.second < num || visit[next])continue;
			q.push(next); visit[next] = true;
		}
	}
	return false;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M; int c, left = INF, right = 0;
	while (M--)
	{
		cin >> s >> e >> c; v[s].push_back({ e,c }); v[e].push_back({ s,c });
		left = min(c, left); right = max(c, right);
	}
	cin >> s >> e;
	while (left <= right) {
		int mid = (left + right) / 2;
		bool check = bfs(mid);
		if (check) { left = mid + 1; result = max(result, mid); }
		else  right = mid - 1; 
	}cout << result;
	return 0;
}

