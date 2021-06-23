#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

int item[101];
int betweenDist[101][101];
int N, M, R;
int itemSum[101];
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (i != j)betweenDist[i][j] = INF;
		}
	for (int i = 1; i <= N; i++)cin >> item[i];
	while (R--) {
		int from, to, dist; cin >> from >> to >> dist;
		betweenDist[from][to] = min(betweenDist[from][to], dist);
		betweenDist[to][from] = min(betweenDist[to][from], dist);
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++){
				if (betweenDist[i][j] > betweenDist[i][k] + betweenDist[k][j]) {
					betweenDist[i][j] = betweenDist[i][k] + betweenDist[k][j];
				}
			}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++){
			if (betweenDist[i][j] <= M)itemSum[i] += item[j];
		}
	cout << *max_element(itemSum, itemSum + N + 1);
;	return 0;
}
