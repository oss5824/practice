#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int num = 0;
	
	cin >> num;
	int* height = new int[num];
	int* width = new int[num];
	int store[15][14];
	memset(store, 0, sizeof(store));
	for (int i = 0; i < 14; i++)store[0][i] = i + 1;

	for (int i = 1; i <= 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (j == 0)store[i][0] = 1;
			else
			{
				int result = 0;
				for (int k = 0; k <= j; k++)result += store[i - 1][k];
				store[i][j] = result;
			}
		}
	}
	for (int i = 0; i < num; i++)cin >> height[i] >> width[i];

	for (int i = 0; i < num; i++)
		cout << store[height[i]][width[i] - 1] << endl;
	return 0;
} 

