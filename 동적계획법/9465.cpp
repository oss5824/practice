#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int T, N, arr[2][100000];
int M[2][100000];
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N;
		memset(arr, 0, sizeof(arr)); memset(M, 0, sizeof(M));
		for (int i = 0; i < 2; i++)for (int j = 0; j < N; j++)cin >> arr[i][j];
		M[0][0] = arr[0][0]; M[1][0] = arr[1][0];
		M[0][1] = arr[0][1] + arr[1][0]; M[1][1] = arr[0][0] + arr[1][1];
		for (int i = 2; i < N; i++)
		{
			M[0][i] = max(M[1][i - 2], max(M[1][i - 1], M[0][i - 2])) + arr[0][i];
			M[1][i] = max(M[0][i - 2], max(M[0][i - 1], M[1][i - 2])) + arr[1][i];
		}
		int result = max(M[0][N - 1], M[1][N - 1]);
		cout << result << "\n";
	}
	return 0;
}