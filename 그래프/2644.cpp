#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int N, M;
vector<int>v[101];
bool visit[101];
void bfs(int a,int b)
{
	queue<pair<int, int>>q; q.push({ a,0 }); visit[a] = true;
	while (!q.empty()) {
		int cur = q.front().first, cur_dist = q.front().second; q.pop();
		if (cur == b) { cout << cur_dist; return; }
		for (int next : v[cur]){
			if (visit[next])continue;
			visit[next] = true; q.push({ next,cur_dist + 1 });
		}
	}
	cout << "-1";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int a, b; cin >> N >> a >> b >> M;
	while (M--) {
		int c, d; cin >> c >> d; v[c].push_back(d); v[d].push_back(c);
	}
	bfs(a, b);
	return 0;
}


