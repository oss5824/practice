#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int num = 0;
	int result = 0;
	cin >> num;
	char** str = new char* [num];
	for (int i = 0; i < num; i++) str[i] = new char[101];
	for (int i = 0; i < num; i++)cin >> str[i];
	for (int i = 0; i < num; i++)
	{
		int len = strlen(str[i]);
		int store[26];
		memset(store, -1, sizeof(int) * 26);
		for (int j = 0; j < len; j++)
		{
			if (store[str[i][j] - 97] == j - 1 || store[str[i][j] - 97] == -1)
				store[str[i][j] - 97] = j;
			else break;
			result = (j == len - 1) ? result + 1 : result;
		}
	}
	printf("%d", result);
	return 0;
}

