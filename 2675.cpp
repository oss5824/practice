#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int T = 0;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n = 0;
		char str[21];
		cin >> n >> str;

		int len = strlen(str);
		for (int j = 0; j < len; j++)for (int k = 0; k < n; k++)printf("%c", str[j]);
		printf("\n");
	}
	return 0;
}

