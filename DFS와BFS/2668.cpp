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
int N;
vector<int>v[101];
bool visit[101];
bool dfs(int start,int cur)
{
	if (start == cur)return true;
	if (visit[cur])return false;
	visit[cur] = true;
	for (int next : v[cur])return dfs(start, next);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) { int a; cin >> a; v[i].push_back(a); }
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			bool backUpVisit[101];
			memcpy(backUpVisit, visit, sizeof(visit));
			bool check = dfs(i, v[i][0]);
			if (!check) { memcpy(visit, backUpVisit, sizeof(visit)); }
			else { visit[i] = true; }
		}
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++)if (visit[i])cnt++;
	cout << cnt << "\n";
	for (int i = 1; i <= N; i++)if (visit[i])cout << i << "\n";
	return 0;
}

