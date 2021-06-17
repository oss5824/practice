#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<limits.h>
#include<string>
#include<queue>
#define INF 1e9
typedef unsigned long long ull;
using namespace std;
int N, M, arr[100000];
bool check(int num)
{
	int sum = 0, cnt = 1;
	for (int i = 0; i < N; i++)
	{
		if (sum + arr[i] > num) {  sum = 0; cnt++; }
		sum += arr[i];
	}
	if (cnt <= M)return true;
	else return false;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	int s = 0, e = 0, result = INF;
	for (int i = 0; i < N; i++) { cin >> arr[i]; e += arr[i]; s = max(s, arr[i]); }
	while (s <= e)
	{
		int m = (s + e) / 2;
		if (check(m)) { result = min(result, m); e = m - 1; }
		else s = m + 1;
	}
	cout << result;

	return 0;
}


