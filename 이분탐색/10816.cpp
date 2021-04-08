#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	long long* arr = new long long[n];
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);
	int count = 0;
	cin >> count;
	long long* search = new long long[count];
	for (int i = 0; i < count; i++)cin >> search[i];
	for (int i = 0; i < count; i++)
	{
		long long value = search[i];
		int start = 0, end = n - 1, mid;
		int num = 0;
		while (end-start>=0)
		{
			mid = (start + end) / 2;
			if (arr[mid] > value)end = mid - 1;
			else if (arr[mid] < value)start = mid + 1;
			else
			{
				num++;
				int back = mid - 1, forward = mid + 1;
				while (back >= 0 && arr[mid] == arr[back--])num++;
				while (forward < n && arr[mid] == arr[forward++])num++;
				break;
			}
		}
		printf("%d ", num);
	}
	return 0;
}
