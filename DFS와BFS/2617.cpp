#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M, result;
bool visit[100][100], visit2[100][100];
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	while (M--) {
		int a, b;
		cin >> a >> b; visit[a][b] = true; visit2[b][a] = true;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (visit[i][k] && visit[k][j])
					visit[i][j] = true;
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)if (visit[i][j])cnt++;
		if (cnt > N / 2) result++;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (visit2[i][k] && visit2[k][j])
					visit2[i][j] = true;
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)if (visit2[i][j])cnt++;
		if (cnt > N / 2)result++;
	}
	cout << result;
	return 0;
}