#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M, cnt;
int dist[20001];
int result, idx;
vector<int>v[20001];
vector<int>res;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	fill(dist, dist + N + 1, INF);
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b; v[a].push_back(b); v[b].push_back(a);
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	q.push({ 0,1 }); dist[1] = 0;
	while (!q.empty())
	{
		int cur = q.top().second, curD = q.top().first; q.pop();
		result = max(result, curD);
		if (dist[cur] < curD)continue;
		for (int next : v[cur])
		{
			if (dist[next] > dist[cur] + 1) {
				dist[next] = dist[cur] + 1;
				q.push({ dist[next],next });
			}
		}
	}
	for (int i = 1; i <= N; i++)if (result == dist[i])res.push_back(i);
	cout << res[0] << " " << result << " " << res.size();
	return 0;
}