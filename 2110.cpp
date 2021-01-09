#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, num;
bool can(unsigned long long mid, vector<unsigned long long>v)
{
	unsigned long long start = v[0];
	int c = 1;
	for (int i = 0; i < n; i++)
	{
		if (v[i] - start >= mid)
		{
			c++;
			start = v[i];
			if (c == num)return true;
		}
	}
	return false;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	unsigned long long res = 0;
	cin >> n >> num;
	vector<unsigned long long>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	sort(v.begin(), v.end());
	unsigned long long low = 1, high = v[n - 1] - v[0];
	while (low <= high)
	{
		unsigned long long mid = (low + high) / 2;
		if (can(mid, v))
		{
			res = max(res, mid);
			low = mid + 1;
		}
		else high = mid - 1;
	}
	printf("%llu", res);
	return 0;
}

