#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int T, N, M, K, i, j; cin >> T;
	while (T--) {
		cin >> N >> M >> K; int s = 0, c = 0, a[200000] = { 0, };
		for (i = 1; i <= N; i++)cin >> a[i];
		for (i = N + 1, j = 1; j < N; i++, j++) a[i] = a[j];
		for (i = 1; i < M; i++)s += a[i];
		for (i = 0, j = M; i < N; i++, j++) { s = s - a[i] + a[j];if (s < K)c++; }
		if (N == M && c != 0)c = 1;
		cout << c << "\n";
	}
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);