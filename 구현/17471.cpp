#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, result = INF;
vector<int> Connect[11];
vector<int>v;
bool visit[11];
int dist[11];
bool visit2[11];
void bfs(int s)
{
	memset(visit2, false, sizeof(visit2));
	queue<int>q; q.push(s); visit2[s] = true;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int next : Connect[cur]) {
			if (!visit2[next] && visit[cur] == visit[next]) {
				q.push(next); visit2[next] = true;
			}
		}
	}
}
void Check()
{
	int len = v.size();
	if (len == 0 || len == N)return;
	vector<int>tmp;
	for (int i = 1; i <= N; i++)if (!visit[i])tmp.push_back(i);
	int len2 = tmp.size();
	bfs(v[0]);
	for (int i = 0; i < len; i++)if (!visit2[v[i]])return;
	bfs(tmp[0]);
	for (int i = 0; i < len2; i++)if (!visit2[tmp[i]])return;
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < len; i++) sum1 += dist[v[i]];
	for (int i = 0; i < len2; i++) sum2 += dist[tmp[i]];
	result = min(result, abs(sum1 - sum2));
}
void solve(int num)
{
	if (v.size() == N)return;
	for (int i = num; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			v.push_back(i);
			Check();
			solve(i);
			v.pop_back();
			visit[i] = false;
		}
	}
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> dist[i];
	for (int i = 1; i <= N; i++) {
		int M, a; cin >> M;
		for (int j = 0; j < M; j++) { cin >> a; Connect[i].push_back(a); Connect[a].push_back(i); }
	}
	solve(1);
	if (result == INF)result = -1; cout << result;
	return 0;
}