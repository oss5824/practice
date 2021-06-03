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
int N, M;
char Map[50][51];
char Map2[50][51];
void reverse_matrix(int x, int y)
{
	for (int i = y; i < y + 3; i++)
		for (int j = x; j < x + 3; j++)
			Map[i][j] = Map[i][j] == '0' ? '1' : '0';
}
bool check()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (Map[i][j] != Map2[i][j])return false;
	return true;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	int cnt = 0;
	bool fin = false;
	for (int i = 0; i < N; i++)cin >> Map[i];
	for (int i = 0; i < N; i++)cin >> Map2[i];
	if (N < 3 || M < 3)
	{
		if (check())cout << "0";
		else cout << "-1";
		return 0;
	}
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			if (Map[i][j] == Map2[i][j])continue;
			reverse_matrix(j, i);
			cnt++;
			if (fin = check())break;
		}
		if (fin)break;
	}
	if (fin)cout << cnt; else cout << "-1";
	return 0;
}
