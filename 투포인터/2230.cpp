#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int s = 0, e = 0, N, M, arr[100000], res = 2e9 + 1;
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> arr[i]; sort(arr, arr + N);
	while (1) {
		if (s == e)e++;
		if (e == N)break;
		int diff = arr[e] - arr[s];
		if (diff >= M) {if (res > diff) { res = diff; }s++;}
		else e++;
	}
	cout << res;
	return 0;
}
