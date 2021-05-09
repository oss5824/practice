#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;

int N, K;
int dx[5] = { 0,1,-1,0,0 }, dy[5] = { 0,0,0,-1,1 };
int Map[13][13];
vector<pair<int, int>>v[13][13];//번호, 방향
vector<pair<int, int>>order;
bool visit[13];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)cin >> Map[i][j];
	order.push_back({ -1,-1 });
	for (int i = 1; i <= K; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a][b].push_back({ i,c });
		order.push_back({ b,a });
		visit[i] = true;
	}
	int cnt = 1;
	while (cnt <= 1000)
	{
		int len = order.size();
		bool check = false;
		for (int i = 1; i <= len; i++)
		{
			if (!visit[i])continue;
			int x = order[i].first, y = order[i].second;
			//cout << "start " << i << " : " << x << "," << y << "\n";
			int direction = v[y][x][0].second;
			bool range = false;
			int nextX = x + dx[direction], nextY = y + dy[direction];
			if (nextX<1 || nextX>N || nextY<1 || nextY>N) { range = true; }
			if (!range && Map[nextY][nextX] == 0)
			{
				int len = v[y][x].size();
				if (v[nextY][nextX].size() == 0)order[i] = { nextX,nextY };
				else { visit[i] = false; }
				for (int i = 0; i < len; i++)v[nextY][nextX].push_back(v[y][x][i]);
				v[y][x].clear();
			}
			else if (!range && Map[nextY][nextX] == 1)
			{
				int len = v[y][x].size();
				reverse(v[y][x].begin(), v[y][x].end());
				int top = v[y][x][0].first;
				if (v[nextY][nextX].size() == 0)
				{
					visit[i] = false; visit[top] = true;
					order[top] = { nextX,nextY };
				}
				else { visit[i] = false; }
				for (int i = 0; i < len; i++)v[nextY][nextX].push_back(v[y][x][i]);
				v[y][x].clear();
			}
			else if (range || Map[nextY][nextX] == 2)
			{
				if (direction == 1)direction = 2;
				else if (direction == 2)direction = 1;
				else if (direction == 3)direction = 4;
				else if (direction == 4)direction = 3;
				v[y][x][0].second = direction;
				nextX = x + dx[direction], nextY = y + dy[direction];
				bool range2 = false;
				if (nextX<1 || nextX>N || nextY<1 || nextY>N)range2 = true;
				if (range2 || Map[nextY][nextX] == 2) {continue; }
				else
				{
					if (Map[nextY][nextX] == 0)
					{
						int len = v[y][x].size();
						if (v[nextY][nextX].size() == 0)order[i] = { nextX,nextY };
						else { visit[i] = false; }
						for (int i = 0; i < len; i++)v[nextY][nextX].push_back(v[y][x][i]);
						v[y][x].clear();
					}
					else if (Map[nextY][nextX] == 1)
					{
						int len = v[y][x].size();
						reverse(v[y][x].begin(), v[y][x].end());
						int top = v[y][x][0].first;
						if (v[nextY][nextX].size() == 0)
						{
							visit[i] = false; visit[top] = true;
							order[top] = { nextX,nextY };
						}
						else { visit[i] = false; }
						for (int i = 0; i < len; i++)v[nextY][nextX].push_back(v[y][x][i]);
						v[y][x].clear();
					}
				}
			}
			if (v[nextY][nextX].size() >= 4) { cout << cnt; return 0; }
		}
		cnt++;
	}
	cout << "-1";
	return 0;
}