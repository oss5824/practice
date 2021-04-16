#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, S, arr[21], res;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> S;
	for (int i = 1; i <= N; i++)cin >> arr[i];
	for (int i = 1; i < (1 << N); i++)
	{
		int n = i, idx = 1, result = 0;
		while (n) {
			if (n & 1) result += arr[idx];
			n = n >> 1; idx++;
		}
		if (result == S)res++;
	}cout << res;
	return 0;
}

