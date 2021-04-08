#include <iostream>
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
using namespace std;
int main()
{
	int n = 0; 
	long long max = 0;
	cin >> n;
	int* store = new int[n];
	int* M = new int [n];
	for (int i = 0; i < n; i++)cin >> store[i];
	M[0] = store[0];
	max = store[0];
	for (int i = 1; i < n; i++)
	{
		M[i] = M[i - 1] + store[i];
		if (M[i] < store[i])M[i] = store[i];
		max = MAX(max, M[i]);
	}
	printf("%d", max);
	return 0;
}
