#include <iostream>
using namespace std;
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
int main()
{
	while (1)
	{
		int n = 0; 
		unsigned long long max = 0;
		cin >> n;
		if (n == 0)break;
		unsigned long long* arr = new unsigned long long[n];
		for (int i = 0; i < n; i++)cin >> arr[i];
		for (int i = 0; i < n; i++)
		{
			unsigned long long start = arr[i];
			for (int j = i + 1; j < n; j++)
			{
				if (arr[i] <= arr[j])start += arr[i];
				else break;
			}
			max = MAX(max, start);
		}
		printf("%llu\n", max);
	}
	return 0;
}