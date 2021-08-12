#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
int Map[6][3], res[6][3];
int t1[15] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 }, t2[15] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };
bool fin;
void solve(int n)
{
	if (n == 15) {
		for (int i = 0; i < 6; i++)for (int j = 0; j < 3; j++)if (res[i][j] != Map[i][j])return;
		fin = true; return;
	}
	int a = t1[n], b = t2[n];
	res[a][0]++; res[b][2]++;
	solve(n + 1);if (fin)return;
	res[a][0]--; res[b][2]--;

	res[a][1]++; res[b][1]++;
	solve(n + 1);if (fin)return;
	res[a][1]--; res[b][1]--;

	res[a][2]++; res[b][0]++;
	solve(n + 1);if (fin)return;
	res[a][2]--; res[b][0]--;
}
int main()
{
	int x = 4;
	while (x--) {
		for (int i = 0; i < 6; i++)for (int j = 0; j < 3; j++)scanf("%d", &Map[i][j]);
		memset(res, 0, sizeof(res));
		fin = false; solve(0); if (fin)printf("1 "); else printf("0 ");
	}
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);