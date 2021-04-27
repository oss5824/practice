#include<iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define INF 1000000000
using namespace std;
int N, M, result = INF;
int arr[101];
bool visit[101];
void bfs()
{
	queue<pair<int, int>>q; q.push({ 1,0 });
	while (!q.empty()) {
		int cur = q.front().first, curD = q.front().second; q.pop();
		if (arr[cur] != 0) { cur = arr[cur]; visit[cur] = true; }
		if (cur == 100) { cout << curD; break; }
		for (int i = 1; i <= 6; i++)
		{
			int next = cur + i;
			if (visit[next])continue;
			q.push({ next,curD + 1 }); visit[next] = true;
		}
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M; int all = N + M;
	while (all--) { int a, b; cin >> a >> b; arr[a] = b; }
	bfs();
	return 0;
}