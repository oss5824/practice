#include <iostream>
#include <cstring>
using namespace std;
int arr1[10001];
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
int main()
{
	ios::sync_with_stdio(false); 
	int n = 0;
	int max = 0;
	cin >> n;
	memset(arr1, 0, sizeof(int) * 10001);
	for (int i = 0; i < n; i++)
	{
		int value = 0;
		cin >> value;
		arr1[value]++;
		max = MAX(max, value);
	}
	for (int i = 1; i <= max; i++)
	{
		int count = arr1[i];
		for (int j = 0; j < count; j++)printf("%d\n", i);
	}
	return 0;
}
