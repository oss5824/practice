#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long n = 0, k = 0;
	cin >> n >> k;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);
	long long start = 1;
	long long end = arr[n - 1];
	long long mid = 0, value = 0;
	while (start <= end)
	{
		long long count = 0;
		mid = (start + end) / 2;
		for (long long i = 0; i < n; i++)count += arr[i] / mid;
		if (count >= k)
		{
			value = mid;
			start = mid + 1;
		}
		else if (count < k)end = mid - 1;
	}
	printf("%lld",value);
	return 0;
}