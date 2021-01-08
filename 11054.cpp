#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n = 0, _max = 0, _max2 = 0, result = 0;
	cin >> n;
	int* arr = new int[n];
	int* M = new int[n];
	int* M2 = new int[n];
	for (int i = 0; i < n; i++)cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		M[i] = 1;
		for (int j = 0; j < i; j++)if (arr[i] > arr[j])M[i] = max(M[i], M[j] + 1);
		_max = max(_max, M[i]);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		M2[i] = 1;
		for (int j = n - 1; j > i; j--)
			if (arr[i] > arr[j])M2[i] = max(M2[i], M2[j] + 1);
		_max2 = max(_max2, M2[i]);
	}
	for (int i = 0; i < n; i++)result = max(result, M[i] + M2[i]);
	printf("%d", result - 1);
	return 0;
}