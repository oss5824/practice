#include<iostream>
using namespace std;
long long arr[1000001], t[4000004];
long long make_tree(int s, int e, int n)
{
	if (s == e)return t[n] = arr[s];
	int m = (s + e) / 2;
	return t[n] = make_tree(s, m, 2 * n) + make_tree(m + 1, e, 2 * n + 1);
}
long long sum(int s, int e, int l, int r, int n)
{
	if (l > e || r < s)return 0;
	if (l <= s && e <= r)return t[n];
	int m = (s + e) / 2;
	return sum(s, m, l, r, 2 * n) + sum(m + 1, e, l, r, 2 * n + 1);
}
void update(int s, int e, int idx, int n, long long val)
{
	if (idx < s || e < idx)return;
	t[n] += val;
	if (s != e)
	{
		int m = (s + e) / 2;
		update(s, m, idx, 2 * n, val); update(m + 1, e, idx, 2 * n + 1, val);
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, k, a; long long b, c; cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	make_tree(0, n - 1, 1);
	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			long long diff = c - arr[b - 1];
			if (diff != 0)update(0, n - 1, b - 1, 1, diff);
			arr[b - 1] = c;
		}
		else cout << sum(0, n - 1, b - 1, c - 1, 1) << "\n";
	}
	return 0;
}