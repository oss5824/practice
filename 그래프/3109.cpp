#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M, result;
char Map[10000][501];
bool check = false;
void dfs(int x,int y)
{
	if (check)return;
	if (Map[y][x] == 'x' || y < 0 || y >= N)return;
	if (x == M - 1) { check = true; result++; return; }
	Map[y][x] = 'x';
	dfs(x + 1, y - 1);
	if (check)return;
	dfs(x + 1, y );
	if (check)return;
	dfs(x + 1, y + 1);
	if (check)return;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> Map[i];
	for (int i = 0; i < N; i++)
	{
		check = false;
		dfs(0, i);
	}cout << result;
	return 0;
}