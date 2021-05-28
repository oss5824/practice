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
#define INF 1e9
using namespace std;
int N, M;
int connect[101][101];
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	int c,d,a,b; 
	cin >> N >> c >> d >> M;
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)connect[i][j] = INF;
	while (M--) { cin >> a >> b; connect[a][b] = 1; connect[b][a] = 1; }
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				if (connect[i][j] > connect[i][k] + connect[k][j])connect[i][j] = connect[i][k] + connect[k][j];
			}
	connect[c][d] == INF ? cout << "-1" : cout << connect[c][d];
	return 0;
}