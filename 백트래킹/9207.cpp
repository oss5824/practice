#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF INT_MAX

using namespace std;
int T, result_sum, move_cnt;
char Map[5][10]; 
pair<int, int>pin[8];
int pin_count;
int len;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
void check(int cnt)
{
	int sum = 0;
	for (int i = 0; i < 5; i++)for (int j = 0; j < 10; j++)if (Map[i][j] == 'o')sum++;
	if (sum < result_sum) { result_sum = sum; if (cnt != 0)move_cnt = cnt; }
	else if (sum == result_sum) { if (cnt != 0)move_cnt = min(move_cnt, cnt); }
}
void solve(int num,int cnt)
{
	check(cnt);
	if (num == pin_count)return;
	for (int i = num; i < len; i++) {
		int x = pin[i].first, y = pin[i].second;
		if (Map[y][x] == '.')continue;
		for (int k = 0; k < 4; k++) {
			int nextX = x + dx[k], nextY = y + dy[k];
			if (nextX < 0 || nextX >= 9 || nextY < 0 || nextY >= 5 || Map[nextY][nextX] != 'o')continue;
			int nextX2 = nextX + dx[k], nextY2 = nextY + dy[k];
			if (nextX2 < 0 || nextX2 >= 9 || nextY2 < 0 || nextY2 >= 5 || Map[nextY2][nextX2] != '.')continue;
			Map[y][x] = '.'; Map[nextY][nextX] = '.'; Map[nextY2][nextX2] = 'o'; pin_count--;
			pin[i] = { nextX2,nextY2 };
			solve(num, cnt + 1);
			Map[y][x] = 'o'; Map[nextY][nextX] = 'o'; Map[nextY2][nextX2] = '.'; pin_count++;
			pin[i] = { x,y };
		}
	}
	solve(num + 1, cnt);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		memset(Map, 0, sizeof(Map)); memset(pin, 0, sizeof(pin)); pin_count = 0;
		for (int i = 0; i < 5; i++)cin >> Map[i];
		for (int i = 0; i < 5; i++)for (int j = 0; j < 9; j++)if (Map[i][j] == 'o')pin[pin_count++] = { j,i };
		result_sum = pin_count; move_cnt = 0; len = pin_count;
		solve(0, 0);
		cout << result_sum << " " << move_cnt << "\n";
	}
	return 0;
}


