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
int N, S, M;
int arr[101];
bool Cache[101][1001];
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++)cin >> arr[i];
	Cache[0][S] = true;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (j + arr[i] <= M) {
				if (Cache[i - 1][j + arr[i]])Cache[i][j] = true;
			}
			if (j - arr[i] >= 0) {
				if (Cache[i - 1][j - arr[i]])Cache[i][j] = true;
			}
		}
	}
	int result = -1;
	for (int i = 0; i <= M; i++)if (Cache[N][i])result = max(i, result);
	cout << result;
;	return 0;
}

