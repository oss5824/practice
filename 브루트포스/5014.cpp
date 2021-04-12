#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int F, S, G, U, D;
bool visit[1000001];
void bfs()
{
	queue<pair<int, int>>q; q.push({ S,0 }); visit[S] = true;
	int dx[2] = { U,-D };
	while (!q.empty()) {
		int curX = q.front().first, curD = q.front().second; q.pop();
		if (curX == G) { cout << curD; return; }
		for (int i = 0; i < 2; i++) {
			int nextX = curX + dx[i];
			if (nextX<1 || nextX>F || visit[nextX])continue;
			visit[nextX] = true; q.push({ nextX,curD + 1 });
		}
	}
	cout << "use the stairs";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> F >> S >> G >> U >> D;
	bfs();
	return 0;
}


