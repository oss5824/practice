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
int N, M;
vector<int>v[2001];
bool visit[2001];
bool check = false;
void dfs(int cur, int bef, int len)
{
	if (check)return;
	if (visit[cur])return;
	if (len >= 4) { check = true; return; }
	visit[cur] = true;
	for (int next : v[cur])
	{
		if (next == bef || visit[next])continue;
		dfs(next, cur, len + 1);
		if (check)return;
		visit[next] = false;
	}
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	while (M--) { int a, b; cin >> a >> b; v[a].push_back(b); v[b].push_back(a); }
	for (int i = 0; i < N; i++)
	{
		memset(visit, false, sizeof(visit));
		dfs(i, -1, 0);
		if (check) { cout << "1"; return 0; }
	}
	if (!check)cout << "0";
	return 0;
}