#include <iostream>
#include <cmath>
using namespace std;
int* arr1, * arr2;
long long cnt;
void MERGE(int s, int m, int e)
{
	int i = s, k = s, j = m + 1;
	while (i <= m && j <= e)
	{
		if (arr2[i] > arr2[j]) cnt += (long long)abs(j - k);
		arr1[k++] = (arr2[i] < arr2[j]) ? arr2[i++] : arr2[j++];
	}
	if (i > m)while (j <= e)arr1[k++] = arr2[j++];
	if (j > e)while (i <= m)arr1[k++] = arr2[i++];
	for (int x = s; x <= e; x++)arr2[x] = arr1[x];
}
void MERGE_SORT(int s, int e)
{
	int m;
	if (s < e)
	{
		m = (s + e) / 2;
		MERGE_SORT(s, m); MERGE_SORT(m + 1, e);
		MERGE(s, m, e);
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n; cin >> n; arr1 = new int[n]; arr2 = new int[n];
	for (int i = 0; i < n; i++)cin >> arr2[i];
	MERGE_SORT(0, n - 1);
	cout << cnt;
	return 0;
}