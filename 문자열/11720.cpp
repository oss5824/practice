#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int n = 0, result = 0;
	char str[101];
	cin >> n;
	cin >> str;
	int len = strlen(str);
	for (int i = 0; i < len; i++)result += str[i] - 48;
	printf("%d", result);
	return 0;
}

