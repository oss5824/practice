#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;
unsigned int N, K, result = INF;
unsigned int Map[401][401];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)Map[i][j] = INF;
	while (K--) {
		int a, b, c; cin >> a >> b >> c;
		Map[a][b] = c;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (Map[i][k] + Map[k][j] < Map[i][j])Map[i][j] = Map[i][k] + Map[k][j];
	for (int i = 1; i <= N; i++)result = min(result, Map[i][i]);
	
	result == INF ? cout << "-1" : cout << result;
	return 0;
}