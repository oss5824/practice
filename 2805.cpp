#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long n = 0, m = 0;
	cin >> n >> m;
	long long* arr = new long long[n];
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);
	long long start = 0;
	long long end = arr[n - 1];
	long long mid, value = 0;
	while (start <= end)
	{
		long long height = 0;
		mid = (start + end) / 2;
		for (long long i = 0; i < n; i++)if (mid <= arr[i])height += arr[i] - mid;
		if (height >= m)
		{
			value = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}
	printf("%lld", value);
	return 0;
}