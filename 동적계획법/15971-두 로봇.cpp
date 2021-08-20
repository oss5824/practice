#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int N, S, E;
bool visit[100001];
vector<pair<int, int>>v[100001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> S >> E;
	while (--N) {
		int s, e, d; cin >> s >> e >> d;
		v[s].emplace_back(e, d); v[e].emplace_back(s, d);
	}
	queue<pair<int, pair<int, int>>>q;//위치, 합, 최댓값
	q.push({ S,{0,0} }); visit[S] = true;
	while (!q.empty()) {
		int cur = q.front().first, sum = q.front().second.first, len = q.front().second.second; q.pop();
		if (cur == E) { cout << sum - len; break; }
		for (pair<int,int> p : v[cur]) {
			int next = p.first, nextD = p.second;
			if (visit[next])continue; visit[next] = true;
			q.push({ next,{sum + nextD,max(len,nextD)} });
		}
	}
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);