#include <iostream>
using namespace std;
int* arr1;
int* arr2;
void MERGE(int start, int mid, int end)
{
	int i = start, j = mid + 1, k = i;
	while (i <= mid && j <= end)
	{
		if (arr2[i] < arr2[j])arr1[k++] = arr2[i++];
		else arr1[k++] = arr2[j++];
	}
	if (i >= mid)while (j <= end)arr1[k++] = arr2[j++];
	if (j >= end)while (i <= mid)arr1[k++] = arr2[i++];
	for (int i = start; i <= end; i++)arr2[i] = arr1[i];
}
void MERGE_SORT(int start, int end)
{
	int mid;
	if (start < end)
	{
		mid = (start + end) / 2;
		MERGE_SORT(start, mid);
		MERGE_SORT(mid + 1, end);
		MERGE(start, mid, end);
	}
}
int main()
{
	int n = 0;
	cin >> n;
	arr1 = new int[n], arr2 = new int[n];
	for (int i = 0; i < n; i++)cin >> arr2[i];
	MERGE_SORT(0, n - 1);
	for (int i = 0; i < n; i++)printf("%d\n", arr2[i]);
	return 0;
}
