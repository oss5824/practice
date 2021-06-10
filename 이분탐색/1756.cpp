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
#define INF 1e9
typedef long long ll;
using namespace std;
int N, M, arr[300000], tmp[300000], order[300000];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M; 
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (i == 0)tmp[i] = arr[i];
		else tmp[i] = min(arr[i], tmp[i - 1]);
	}
	int idx = N - 1, result = 0;
	bool fin = false;
	for (int i = 0; i < M; i++)cin >> order[i];
	int cnt = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (order[cnt] <= tmp[i]) { result = i + 1; cnt++; }
		if (cnt == M)break;
	}
	if (cnt != M)cout << "0";
	else cout << result;
	return 0;
}


