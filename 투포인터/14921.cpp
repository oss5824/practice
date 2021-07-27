#include<iostream>
using namespace std;
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	int N, s = 0, e, a[100000], res = 1e9; cin >> N; e = N - 1; for (int i = 0; i < N; i++)cin >> a[i];
	while (s < e) {
		int n = a[e] + a[s];
		if (n == 0) { cout << "0"; return 0; }
		if (n > 0) { e--; if (n < abs(res))res = n; }
		else { s++; if (-n < abs(res))res = n; }
	}cout << res;
}
