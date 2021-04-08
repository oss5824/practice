#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	char** store = new char* [n];
	for (int i = 0; i < n; i++)store[i] = new char[51];
	for (int i = 0; i < n; i++)cin >> store[i];
	for (int i = 0; i < n; i++)
	{
		int len = strlen(store[i]), left = 0, right = 0, flag = 1;
		for (int j = 0; j < len; j++)
		{
			if (store[i][j] == '(')left++;
			else if (store[i][j] == ')')right++;
			if (left < right)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1 && left == right)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
//#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))