#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[100001], max_t[400004], min_t[400004];
int make_max_tree(int s, int e, int n)
{
	if (s == e) return max_t[n] = arr[s];
	int m = (s + e) / 2;
	return max_t[n] = max(make_max_tree(s, m, 2 * n), make_max_tree(m + 1, e, 2 * n + 1));
}
int make_min_tree(int s, int e, int n)
{
	if (s == e) return min_t[n] = arr[s];
	int m = (s + e) / 2;
	return min_t[n] = min(make_min_tree(s, m, 2 * n), make_min_tree(m + 1, e, 2 * n + 1));
}
int search_max(int s, int e, int l, int r, int n)
{
	if (l > e || s > r)return -1;
	if (l <= s && e <= r) return max_t[n];
	int m = (s + e) / 2;
	return max(search_max(s, m, l, r, 2 * n), search_max(m + 1, e, l, r, 2 * n + 1));
}
int search_min(int s, int e, int l, int r, int n)
{
	if (l > e || s > r)return 100001;
	if (l <= s && e <= r) return min_t[n];
	int m = (s + e) / 2;
	return min(search_min(s, m, l, r, 2 * n), search_min(m + 1, e, l, r, 2 * n + 1));
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int T, n, m, a; int b, c; cin >> T;
	while (T--)
	{
		cin >> n >> m; memset(arr, 0, sizeof(arr)); for (int i = 0; i < n; i++)arr[i] = i;
		make_max_tree(0, n - 1, 1); make_min_tree(0, n - 1, 1);
		while (m--)
		{
			cin >> a >> b >> c;
			if (a == 1)
			{
				int max_val = search_max(0, n - 1, b, c, 1), min_val = search_min(0, n - 1, b, c, 1);
				bool check = false; if (max_val == c && min_val == b)check = true;
				if (check)cout << "YES\n"; else cout << "NO\n";
			}
			else
			{
				int tmp = arr[b]; arr[b] = arr[c]; arr[c] = tmp;
				memset(max_t, -1, sizeof(max_t)); memset(min_t, -1, sizeof(min_t));
				make_max_tree(0, n - 1, 1); make_min_tree(0, n - 1, 1);
			}
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
ll arr[100001], t[400004];
ll make_tree(int s, int e, int n)
{
	if (s == e) return t[n] = arr[s];
	int m = (s + e) / 2;
	return t[n] = (make_tree(s, m, 2 * n) + make_tree(m + 1, e, 2 * n + 1));
}
ll sum(int s, int e, int l, int r, int n)
{
	if (l > e || s > r)return 0;
	if (l <= s && e <= r) return t[n];
	int m = (s + e) / 2;
	return (sum(s, m, l, r, 2 * n) + sum(m + 1, e, l, r, 2 * n + 1));
}
void update(int s, int e, int i, int n, ll d)
{
	if (i < s || e < i) return;
	t[n] += d;
	if (s != e) { int m = (s + e) / 2; update(s, m, i, 2 * n, d); update(m + 1, e, i, 2 * n + 1, d); }
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int T, n, m, a; ll b, c; cin >> T;
	while (T--)
	{
		cin >> n >> m;
		memset(arr, 0, sizeof(arr)); memset(t, -1, sizeof(t));
		for (int i = 0; i < n; i++)arr[i] = i;
		make_tree(0, n - 1, 1);
		while (m--)
		{
			cin >> a >> b >> c;
			if (a == 1)
			{
				ll res = sum(0, n - 1, (int)b, (int)c, 1), val = (c * (c + 1)) / 2 - (b * (b - 1) / 2);
				bool check = (res == val) ? true : false;
				if (check)cout << "YES\n"; else cout << "NO\n";
			}
			else
			{
				update(0, n - 1, b, 1, arr[c] - arr[b]); update(0, n - 1, c, 1, arr[b] - arr[c]);
				ll tmp = arr[b]; arr[b] = arr[c]; arr[c] = tmp;
			}
		}
	}
	return 0;
}
