#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
using namespace std;
typedef unsigned long long ull;
queue<pair<int, int>>q;
queue<pair<int, int>>store_q;
vector<pair<int, int>>v;
vector<int>tmp;
int Map[8][8], backUpMap[8][8];
bool visit[64];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int N, M, len, result;
int Count()
{
	int cnt = 0; for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)if (Map[i][j] == 0)cnt++;
	return cnt;
}
void bfs()
{
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N|| Map[nextY][nextX] != 0)continue;
			q.push({ nextX,nextY }); Map[nextY][nextX] = 2;
		}
	}
}
void Set(int num)
{
	if (tmp.size() == 3){
		q = store_q;  memcpy(backUpMap, Map, sizeof(Map));
		for (int i = 0; i < 3; i++) { int x = v[tmp[i]].first, y = v[tmp[i]].second; Map[y][x] = 1; }
		bfs(); int value = Count(); result = max(result, value);
		memcpy(Map, backUpMap, sizeof(Map));
		return;
	}
	for (int i = num; i < len; i++){
		if (!visit[i]){
			visit[i] = true;
			tmp.push_back(i);
			Set(i);
			visit[i] = false;
			tmp.pop_back();
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++){
			cin >> Map[i][j];
			if (Map[i][j] == 0)v.push_back({ j,i });
			else if (Map[i][j] == 2) store_q.push({ j,i });
		}
	len = v.size(); Set(0); cout << result;
	return 0;
}

