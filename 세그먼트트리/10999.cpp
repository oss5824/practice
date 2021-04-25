#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#include<limits.h>
#define INF 987654321
using namespace std;
typedef long long ll;
ll N, M, K, arr[1000000], t[4000000],lz[4000000];
vector<int>v;
ll init(int s, int e, int n)
{
	if (s == e)return t[n] = arr[s];
	int m= (s + e) / 2;
	return t[n] = init(s, m, 2 * n) + init(m + 1, e, 2 * n + 1);
}
void lazy(int s, int e, int l, int r, int n)
{
	if (lz[n] != 0)
	{
		ll len = e - s + 1;
		t[n] += len * lz[n];
		if (s != e)
		{
			lz[2 * n] += lz[n];
			lz[2 * n + 1] += lz[n];
		}
		lz[n] = 0;
	}
}
void update(int s, int e, int l,int r, ll diff, int n)
{
	lazy(s, e, l, r, n);
	if (s > r || e < l)return;
	if (l <= s && e <= r)
	{
		ll len = e - s + 1;
		t[n] += len * diff;
		if (s != e)
		{
			lz[2 * n] += diff;
			lz[2 * n + 1] += diff;
		}
		return;
	}
	int m = (s + e) / 2;
	update(s, m, l, r, diff, 2 * n); update(m + 1, e, l, r, diff, 2 * n + 1);
	t[n] = t[2 * n] + t[2 * n + 1];
}
ll sum(int s, int e, int l, int r, int n)
{
	lazy(s, e, l, r, n);
	if (s > r || e < l)return 0;
	if (l <= s && e <= r)return t[n];
	int m = (s + e) / 2;
	return sum(s, m, l, r, 2 * n) + sum(m + 1, e, l, r, 2 * n + 1);
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)cin >> arr[i];
	init(0, N - 1, 1);
	int Q = M + K;
	while (Q--) {
		ll a, b, c, d; cin >> a;
		if (a == 1)
		{
			cin >> b >> c >> d;
			update(0, N - 1, b - 1, c - 1, d, 1);
		}
		else{
			cin >> b >> c;
			if (b > c)swap(b, c);
			cout << sum(0, N - 1, b - 1, c - 1, 1) << "\n";
		}
	}
	return 0;
}


