#include<iostream>
using namespace std;
long long arr[1000001], t[4000004];
#define M 1000000007
long long make_tree(int s, int e, int n)
{
	if (s == e)return t[n] = (arr[s] % M);
	int m = (s + e) / 2;
	return t[n] = ((make_tree(s, m, 2 * n) % M * make_tree(m + 1, e, 2 * n + 1) % M) % M);
}
long long mul(int s, int e, int l, int r, int n)
{
	if (l > e || s > r)return 1;
	if (l <= s && e <= r)return (t[n] % M);
	int m = (s + e) / 2;
	return  (mul(s, m, l, r, 2 * n) % M * mul(m + 1, e, l, r, 2 * n + 1) % M) % M;
}
long long update(int s, int e, int i, int n, int val)
{
	if (i < s || e < i)return t[n];
	if (s == e)return t[n] = val;
	else { int m = (s + e) / 2; return t[n] = (update(s, m, i, 2 * n, val) % M * update(m + 1, e, i, 2 * n + 1, val) % M) % M; }
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, k, a; long long b, c;
	cin >> n >> m >> k; for (int i = 0; i < n; i++)cin >> arr[i];
	make_tree(0, n - 1, 1);
	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;
		if (a == 1) { update(0, n - 1, b - 1, 1, c); arr[b - 1] = c; }
		else cout << mul(0, n - 1, b - 1, c - 1, 1) % M << "\n";
	}
	return 0;
}