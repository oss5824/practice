#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
#include<string>
#define INF 987654321
typedef unsigned long long ull;
using namespace std;
int N, M, cnt;
vector<int>v[501];
bool visit[501];
bool bfs(int num)
{
	queue<pair<int, int>>q; q.push({ 1,0 }); memset(visit, false, sizeof(visit)); visit[1] = true;
	while (!q.empty()) {
		int cur = q.front().first, cur_dist = q.front().second; q.pop();
		if (cur == num){
			if (cur_dist <= 2)return true;
			else return false;
		}
		for (int p : v[cur])
		{
			int num = p;
			if (visit[num])continue;
			q.push({ num, cur_dist + 1 }); visit[num] = true;
		}
	}
	return false;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M; 
	for (int i = 0; i < M; i++) { int a, b; cin >> a >> b; v[a].push_back(b); v[b].push_back(a); }
	for (int i = 2; i <= N; i++)if (bfs(i))  cnt++;
	cout << cnt;
	return 0;
}

