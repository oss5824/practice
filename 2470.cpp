#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long* arr = new long long[n];
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);
	if (arr[0] > 0 && arr[1] > 0)printf("%lld %lld", arr[0], arr[1]);
	else if (arr[n - 2] < 0 && arr[n - 1] < 0)printf("%lld %lld", arr[n - 2], arr[n - 1]);
	else
	{
		int start = 0, end = n - 1;
		long long min_value = 2000000000;
		pair<long long, long long>p;
		while (start < end)
		{
			long long value = arr[end] + arr[start];
			if (min_value > (long long)abs(value))
			{
				min_value = (long long)abs(value);
				p.first = arr[start];
				p.second = arr[end];
			}
			if (value > 0)end--;
			else if (value < 0)start++;
			else break;
		}
		printf("%lld %lld", p.first, p.second);
	}
	return 0;
}
