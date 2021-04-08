#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int vmax = 0;
	int* start = new int[n];
	int* end = new int[n];
	int* M = new int[n];
	M[0] = 0;
	for (int i = 0; i < n; i++)cin >> start[i] >> end[i];
	for (int i = 0; i < n; i++)
	{
		int b = 0;
		int j = 0, count = M[i];
		for (; j <= i; j++)
		{
			if (b<=start[j] && end[j] <= end[i])
			{
				b = end[j];
				count++;
			}
		}
		for (j = i ; j < n; j++)
		{
			if (b <= start[j])
			{
				b = end[j];
				count++;
			}
		}
		vmax = max(vmax, count);
		M[i] = vmax;
	}
	printf("%d", vmax);
	return 0;
}