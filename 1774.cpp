#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
vector<pair<int, long long>> v[1001];
bool visit[1001];
double result;
void prim(int num)
{
	visit[num] = true;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
	int len = v[num].size();
	for (int i = 0; i < len; i++)pq.push({ v[num][i].second, v[num][i].first });
	while (!pq.empty())
	{
		int cur = pq.top().second;
		long long cur_dist = pq.top().first;
		pq.pop();
		if (visit[cur])continue;
		visit[cur] = true;
		len = v[cur].size();
		result += sqrt(cur_dist);
		for (int i = 0; i < len; i++)pq.push({ v[cur][i].second ,v[cur][i].first });
	}
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	int n, m, len, start; cin >> n >> m;
	vector<pair<long long, long long>>r;
	r.push_back({ 0,0 });
	for (int i = 0; i < n; i++) { long long a, b; cin >> a >> b; r.push_back({ a,b }); }
	len = r.size();
	for (int i = 1; i < len; i++)
		for (int j = i + 1; j < len; j++)
		{
			long long d = (r[i].first - r[j].first) * (r[i].first - r[j].first)
				+ (r[i].second - r[j].second) * (r[i].second - r[j].second);
			v[i].push_back({ j,d }); v[j].push_back({ i,d });
		}
	int a, b;
	cin >> a >> b; start = a; v[a].push_back({ b, 0 }); v[b].push_back({ a, 0 });
	for (int i = 1; i < m; i++) { cin >> a >> b; v[a].push_back({ b, 0 }); v[b].push_back({ a, 0 }); }
	prim(start);
	printf("%.2f", result);
	return 0;
}