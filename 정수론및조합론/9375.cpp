#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int test = 0, plus = 1;
	int res[31] = { 0, };
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		int n = 0, result = 1;
		cin >> n;
		char name[31][21];
		char position[31][21];
		for (int j = 0; j < n; j++)cin >> name[j] >> position[j];
		int count[31] = { 0, };
		for (int j = 0; j < n; j++)
		{
			if (atoi(position[j]) != 0)continue;
			count[j] = 1;
			for (int k = j + 1; k < n; k++)
			{
				if ((!strcmp(position[j], position[k])))
				{
					count[j]++;
					sprintf(position[k], "%d", plus++);
				}
			}
		}
		for (int j = 0; j < n; j++)
			if (count[j] > 0)
				result *= (count[j] + 1);
		res[i] = result - 1;
	}
	for (int i = 0; i < test; i++)printf("%d\n", res[i]);
	return 0;
}
//#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))