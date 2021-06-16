#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<limits.h>
#define INF 1e9
using namespace std;
int N, M, res;
int result[7];
bool know[10], visit[10];

void solve(int num,int cnt)
{
	if (cnt == N)
	{
		int num = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < N; i++) { if (know[result[i]])visit[result[i]] = true; }
		for (int i = 0; i < 10; i++)if (visit[i])num++;
		if (num == M)res++;
		 return;
	}
	for (int i = num; i <= 9; i++) {
		result[cnt] = i;
		solve(num, cnt + 1);
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++) { int a; cin >> a; know[a] = true; }
	solve(0, 0);
	cout << res;
	return 0;
}


