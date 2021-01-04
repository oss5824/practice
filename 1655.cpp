#include <iostream>
#include <algorithm>
using namespace std;
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sort(arr, arr + i + 1);
		if (i == 0)printf("%d\n", arr[i]);
		else if (i % 2 == 0)printf("%d\n", arr[i / 2]);
		else if (i % 2 == 1)printf("%d\n", MIN(arr[i / 2], arr[(i / 2) + 1]));
	}
	return 0;
}