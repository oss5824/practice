#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
#define INF 987654321
using namespace std;
int arr[11];
int result[11];
int N, M;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; fill(result, result + 11, INF);
	for (int i = 1; i <= N; i++)cin >> arr[i];
	for (int i = 1; i <= N; i++)
	{
		int cnt = arr[i] + 1;
		for (int j = 1; j <= N; j++)
		{
			if (i < result[j])cnt--;
			if (cnt == 0) { result[j] = i; break; }
		}
	}
	for (int i = 1; i <= N; i++)cout << result[i] << " ";
	return 0;
}
