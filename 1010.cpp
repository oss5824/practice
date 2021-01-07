#include <iostream>
#include <cstring>
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n = 0;
	unsigned long long max = 0;
	cin >> n;
	int* west = new int[n];
	int* east = new int[n];
	unsigned long long store[31][31];
	for (int i = 0; i < n; i++)cin >> west[i] >> east[i];
	for (int i = 0; i < n; i++)
	{
		int w = west[i], e = east[i];
		if (w == e)printf("1\n");
		else
		{
			memset(store, 0, sizeof(unsigned long long) * (31) * (31));
			for (int i = 0; i < e; i++)
			{
				store[i][0] = 1, store[i][i] = 1;
				for (int j = 0; j < i; j++)store[i + 1][j + 1] = store[i][j] + store[i][j + 1];
			}
			printf("%llu\n", store[e][w]);
		}
	}
	
	return 0;
}