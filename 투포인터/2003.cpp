#include<iostream>
using namespace std;
typedef unsigned long long ull;
ull arr[10000],M;
int N;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> arr[i];
	ull s = 0, e = 0, sum = 0,cnt=0;
	while (s <= e)
	{
		if (M <= sum) { if (sum == M) cnt++; sum -= arr[s++]; }
		else if (e >= N)break;
		else { sum += arr[e++]; }
	}cout << cnt;
	return 0;
}

