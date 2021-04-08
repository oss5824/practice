#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;
long long dist[101][101];
int V, E;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> V >> E;
	for (int i = 1; i <= V; i++)for (int j = 1; j <= V; j++)dist[i][j] = (i != j) ? INF : 0;
	for (int i = 0; i < E; i++)
	{
		int a, b, value;
		cin >> a >> b >> value;
		dist[a][b] = min(dist[a][b], (long long)value);
	}
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			for (int k = 1; k <= V; k++)
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (dist[i][j] == INF)printf("0 ");
			else printf("%lld ", dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}
