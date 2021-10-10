#pragma warning(disable: 4996)
#include<stdio.h>
#define max(a,b) (a)>(b)?(a):(b)
int N, M, arr[101][101];
typedef long long ll;
ll res;
ll rect(int x1, int y1, int x2, int y2) {
	ll sum = 0;
	for (int i = y1; i <= y2; i++)sum += arr[i][x2] - arr[i][x1 - 1];
	return sum;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		char s[102]; scanf("%s", s);
		for (int j = 1, sum = 0; j <= M; j++)sum += s[j - 1] - '0', arr[i][j] = sum;
	}
	for (int i = 1; i < M - 1; i++)
		for (int j = i + 1; j < M; j++) {
			ll a = rect(1, 1, i, N), b = rect(i + 1, 1, j, N), c = rect(j + 1, 0, M, N);
			res = max(res, a * b * c);
		}
	for (int i = 1; i < N - 1; i++)
		for (int j = i + 1; j < N; j++) {
			ll a = rect(1, 1, M, i), b = rect(1, i + 1, M, j), c = rect(1, j + 1, M, N);
			res = max(res, a * b * c);
		}

	for (int i = 1; i < M; i++)
		for (int j = 1; j < N; j++) {
			ll a = rect(1, 1, i, N), b = rect(i + 1, 1, M, j), c = rect(i + 1, j + 1, M, N);
			res = max(res, a * b * c);
		}
	for (int i = 1; i < N; i++)
		for (int j = 1; j < M; j++) {
			ll a = rect(1, 1, M, i), b = rect(1, i + 1, j, N), c = rect(j + 1, i + 1, M, N);
			res = max(res, a * b * c);
		}

	for (int i = M; i > 1; i--)
		for (int j = 1; j < N; j++) {
			ll a = rect(i, 1, M, N), b = rect(1, 1, i - 1, j), c = rect(1, j + 1, i - 1, N);
			res = max(res, a * b * c);
		}
	for (int i = N; i > 1; i--)
		for (int j = 1; j < M; j++) {
			ll a = rect(1, i, M, N), b = rect(1, 1, j, i - 1), c = rect(j + 1, 1, M, i - 1);
			res = max(res, a * b * c);
		}printf("%lld", res);
}
