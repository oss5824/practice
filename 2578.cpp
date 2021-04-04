#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
#define INF 987654321
using namespace std;
int Map[5][5], result, cnt;
bool visit[5][5];
bool check()
{
	int cnt = 0;
	for (int i = 0; i < 5; i++){
		if (visit[i][0] && visit[i][1] && visit[i][2] && visit[i][3] && visit[i][4])cnt++;
		if (visit[0][i] && visit[1][i] && visit[2][i] && visit[3][i] && visit[4][i])cnt++;
	}
	if (visit[0][0] && visit[1][1] && visit[2][2] && visit[3][3] && visit[4][4])cnt++;
	if (visit[0][4] && visit[1][3] && visit[2][2] && visit[3][1] && visit[4][0])cnt++;
	if (cnt >= 3)return true;
	else return false;
}
void exist(int num) {
	for (int i = 0; i < 5; i++)for (int j = 0; j < 5; j++)if (Map[i][j] == num) { visit[i][j] = true; return; }
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	for (int i = 0; i < 5; i++)for (int j = 0; j < 5; j++)cin >> Map[i][j];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			int a;
			cin >> a; exist(a); cnt++;
			if (check() && result == 0)result = cnt;
		}
	cout << result;
	return 0;
}

