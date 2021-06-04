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
typedef unsigned long long ull;
using namespace std;
ull N, M, arr[100000];
bool check(ull m)
{
	ull cnt = 0;
	for (int i = 0; i < N; i++)cnt += (m / arr[i]);
	if (cnt >= M)return true;
	else return false;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M; for (int i = 0; i < N; i++)cin >> arr[i];
	sort(arr, arr + N);
	ull s = 0, e = arr[N - 1] * M, result = e;
	while (s <= e) {
		ull m = (s + e) / 2;
		if (check(m)) { e = m - 1; result = min(result, m); }
		else s = m + 1;
	}cout << result;
	return 0;
}
