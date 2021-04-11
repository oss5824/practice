#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, M, result = INF, idx;
int arr[101][101];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M; 
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)if (i != j)arr[i][j] = INF;
	while (M--) {
		int a, b; cin >> a >> b; arr[a][b] = 1; arr[b][a] = 1;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (arr[i][k] + arr[k][j] < arr[i][j])
					arr[i][j] = arr[i][k] + arr[k][j];
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		for (int j = 1; j <= N; j++)sum += arr[i][j];
		if (result > sum) { result = sum; idx = i; }
	}cout << idx;
	return 0;
}


