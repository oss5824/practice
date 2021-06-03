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
int N, result;
int Map[10001][6],side_max[10001][3];
int arr[3][4] = { { 1,2,3,4 },{ 0,1,3,5 },{ 0,2,4,5 } };
//0,5 / 1,3 / 2,4

void solve(int num, int sum, int k)
{
	if (num > N){
		result = max(result, sum);
		return;
	}
	int idx = 0, d = 0, idx2 = 0;
	if (k == 0 || k == 5)d = 0; else if (k == 1 || k == 3)d = 2; else d = 1;
	if (num != N) {
		for (int i = 0; i < 6; i++)if (Map[num][k] == Map[num + 1][i]) { idx = i; break; }
		if (idx == 0)idx2 = 5; else if (idx == 1)idx2 = 3; else if (idx == 2)idx2 = 4;
		else if (idx == 3)idx2 = 1; else if (idx == 4)idx2 = 2; else if (idx == 5)idx2 = 0;
		solve(num + 1, sum + side_max[num][d], idx2);
	}
	else solve(num + 1, sum + side_max[num][d], 0);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Map[i][0] >> Map[i][1] >> Map[i][2] >> Map[i][3] >> Map[i][4] >> Map[i][5];
		for (int j = 0; j < 4; j++) side_max[i][0] = max(side_max[i][0], Map[i][arr[0][j]]);
		for (int j = 0; j < 4; j++) side_max[i][1] = max(side_max[i][1], Map[i][arr[1][j]]);
		for (int j = 0; j < 4; j++) side_max[i][2] = max(side_max[i][2], Map[i][arr[2][j]]);
	}
	for (int i = 0; i < 6; i++)solve(1, 0, i);
	cout << result;
	return 0;
}