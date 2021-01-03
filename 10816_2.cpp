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
	for (int i = 0; i < count; i++)printf("%d ", upper_bound(arr, arr + n, search[i])
		- lower_bound(arr, arr + n, search[i]));
	return 0;
}