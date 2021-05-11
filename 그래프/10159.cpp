#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M;
bool visit[101][101];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	while (M--) {
		int a, b; cin >> a >> b; visit[a][b] = true;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (visit[i][k] && visit[k][j])visit[i][j] = true;
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if ((visit[i][j] || visit[j][i]) || i == j)continue;
			cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}