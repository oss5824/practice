#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, x, cnt = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);
	cin >> x;
	int start = 0, end = n - 1;
	while (start < end)
	{
		if (arr[start] + arr[end] > x)end--;
		else if (arr[start] + arr[end] < x)start++;
		else { start++; end--; cnt++; }
	}
	printf("%d", cnt);
	return 0;
}
