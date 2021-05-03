#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
using namespace std;

int Map[5][5][5], result = INT_MAX;
int dx[6] = { -1,1,0,0,0,0 }, dy[6] = { 0,0,-1,1,0,0 }, dz[6] = { 0,0,0,0,-1,1 };
int sx[4] = { 0,0,4,4 }, sy[4]{ 0,4,0,4 }, sz[4] = { 0,0,0,0 };
int ex[4] = { 4,4,0,0 }, ey[4]{ 4,0,4,0 }, ez[4] = { 4,4,4,4 };

bool check(int a) { if (a < 0 || a >= 5)return false; else return true; }
string s;
vector<string>vs;
map<string, int>m;
bool visit[5];
void bfs(int x1, int y1, int z1, int x2, int y2, int z2)
{
	queue<pair<pair<int, int>, pair<int, int>>>q; q.push({ {x1,y1},{z1,0} });
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second;
		int curZ = q.front().second.first, curD = q.front().second.second; q.pop();
		if (curX == x2 && curY == y2 && curZ == z2) { result = min(result, curD); return; }
		for (int i = 0; i < 6; i++){
			int nextX = curX + dx[i], nextY = curY + dy[i], nextZ = curZ + dz[i];
			if (!check(nextX) || !check(nextY) || !check(nextZ) || Map[nextZ][nextY][nextX] == 0)continue;
			q.push({ {nextX,nextY},{nextZ,curD + 1} }); Map[nextZ][nextY][nextX] = 0;
		}
	}
}

void rotate(int z)
{
	int tmp0 = Map[z][0][0], tmp1 = Map[z][0][1], tmp2 = Map[z][0][2], tmp3 = Map[z][0][3], tmp4 = Map[z][0][4];
	for (int i = 0; i < 5; i++)Map[z][0][4 - i] = Map[z][i][0];
	for (int i = 0; i < 5; i++)Map[z][i][0] = Map[z][4][i];
	for (int i = 0; i < 5; i++)Map[z][4][i] = Map[z][4 - i][4];
	Map[z][4][4] = tmp4; Map[z][3][4] = tmp3;	Map[z][2][4] = tmp2; Map[z][1][4] = tmp1;	Map[z][0][4] = tmp0;

	tmp0 = Map[z][1][1], tmp1 = Map[z][1][2], tmp2 = Map[z][1][3];
	for (int i = 0; i < 3; i++)Map[z][1][3 - i] = Map[z][i + 1][1];
	for (int i = 0; i < 3; i++)Map[z][i + 1][1] = Map[z][3][i + 1];
	for (int i = 0; i < 3; i++)Map[z][3][i + 1] = Map[z][3 - i][3];
	Map[z][3][3] = tmp2; Map[z][2][3] = tmp1;	Map[z][1][3] = tmp0;
}
void solve(int num)
{
	if(s.size()==5){
		if (m[s] == 0) { m[s] = 1; string tmp = s; reverse(tmp.begin(), tmp.end()); m[tmp] = 1; vs.push_back(s); }
		return;
	}
	for (int i = num; i < 5; i++)
		if (!visit[i]){
			visit[i] = true;
			s.push_back(i + '0');
			solve(num);
			s.pop_back();
			visit[i] = false;
		}
}
void make_map(string str)
{
	int tmpMap[5][5][5]; memcpy(tmpMap, Map, sizeof(Map));
	for (int k = 0; k < 5; k++)for (int i = 0; i < 5; i++)for (int j = 0; j < 5; j++)Map[k][i][j] = tmpMap[str[k] - '0'][i][j];
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	solve(0);
	for (int k = 0; k < 5; k++)for (int i = 0; i < 5; i++)for (int j = 0; j < 5; j++)cin >> Map[k][i][j];
	int len = vs.size();
	for (int k = 0; k < len; k++)
	{
		int backUpMap[5][5][5]; memcpy(backUpMap, Map, sizeof(Map));
		make_map(vs[k]);
		for (int a = 0; a < 4; a++) {
			rotate(0);
			for (int b = 0; b < 4; b++) {
				rotate(1);
				for (int c = 0; c < 4; c++) {
					rotate(2);
					for (int d = 0; d < 4; d++) {
						rotate(3);
						for (int e = 0; e < 4; e++) {
							rotate(4);
							for (int i = 0; i < 4; i++)
							{
								if (Map[sz[i]][sy[i]][sx[i]] == 0 || Map[ez[i]][ey[i]][ex[i]] == 0)continue;
								int backUp[5][5][5]; memcpy(backUp, Map, sizeof(Map));
								bfs(sx[i], sy[i], sz[i], ex[i], ey[i], ez[i]);
								memcpy(Map, backUp, sizeof(Map));
							}
						}
					}
				}
			}
		}
		memcpy(Map, backUpMap, sizeof(Map));
	}
	if (result == INT_MAX)result = -1;
	cout << result;
	return 0;
}