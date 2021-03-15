#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
#define INF INT_MAX
using namespace std;
vector<pair<int, int>>v[1001];
int dist[1001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, b, c; cin >> n >> m;
	while (m--) { cin >> a >> b >> c; v[a].push_back({ b,c }); }
	cin >> a >> b; fill(dist, dist + 1001, INF);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	q.push({ 0,a }); dist[a] = 0;
	while (!q.empty()){
		int cur = q.top().second, cur_dist = q.top().first; q.pop();
		if (dist[cur] < cur_dist)continue;
		for (pair<int, int>next : v[cur]){
			if (next.second + cur_dist < dist[next.first]){
				dist[next.first] = next.second + cur_dist; q.push({ next.second,next.first });
			}
		}
	}cout << dist[b];
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);