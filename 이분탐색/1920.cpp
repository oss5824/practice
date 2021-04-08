#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);
	int count = 0;
	cin >> count;
	int* search = new int[count];
	for (int i = 0; i < count; i++)cin >> search[i];
	for (int i = 0; i < count; i++)
	{
		if (binary_search(arr, arr + n, search[i]))printf("1\n");
		else printf("0\n");
	}
	return 0;
}
