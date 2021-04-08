#include<iostream>
#include<algorithm>
using namespace std;
int arr[100001], max_t[400004], min_t[400004];
int make_min_tree(int s, int e, int n)
{
	if (s == e)return min_t[n] = arr[s];
	int m = (s + e) / 2;
	return min_t[n] = min(make_min_tree(s, m, 2 * n), make_min_tree(m + 1, e, 2 * n + 1));
}
int make_max_tree(int s, int e, int n)
{
	if (s == e)return max_t[n] = arr[s];
	int m = (s + e) / 2;
	return max_t[n] = max(make_max_tree(s, m, 2 * n), make_max_tree(m + 1, e, 2 * n + 1));
}
int search_min(int s, int e, int l, int r, int n)
{
	if (l > e || s > r)return 1000000001;
	if (l <= s && e <= r)return min_t[n];
	int m = (s + e) / 2;
	return min(search_min(s, m, l, r, 2 * n), search_min(m + 1, e, l, r, 2 * n + 1));
}
int search_max(int s, int e, int l, int r, int n)
{
	if (l > e || s > r)return -1;
	if (l <= s && e <= r)return max_t[n];
	int m = (s + e) / 2;
	return max(search_max(s, m, l, r, 2 * n), search_max(m + 1, e, l, r, 2 * n + 1));
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, b; cin >> n >> m; for (int i = 0; i < n; i++)cin >> arr[i];
	make_max_tree(0, n - 1, 1); make_min_tree(0, n - 1, 1);
	while (m--) { cin >> a >> b; cout << search_min(0, n - 1, a - 1, b - 1, 1) << " " << search_max(0, n - 1, a - 1, b - 1, 1) << "\n"; }
	return 0;
}