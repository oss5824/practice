#include<iostream>
using namespace std;
int arr[100001], t[400004];
int make_tree(int s, int e, int n)
{
	if (s == e)return t[n] = arr[s];
	int m = (s + e) / 2;
	return t[n] = make_tree(s, m, 2 * n) + make_tree(m + 1, e, 2 * n + 1);
}
int sum(int s, int e, int l, int r, int n)
{
	if (l > e || r < s)return 0;
	if (l <= s && e <= r)return t[n];
	int m = (s + e) / 2;
	return sum(s, m, l, r, 2 * n) + sum(m + 1, e, l, r, 2 * n + 1);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, b; cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> arr[i];
	make_tree(0, n - 1, 1);
	while (m--) { cin >> a >> b; cout << sum(0, n - 1, a - 1, b - 1, 1) << "\n"; }
	return 0;
}