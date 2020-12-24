#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int n = 0, result = 0;
	char str[101];
	cin >> str;
	int len = strlen(str);
	int* store = new int[26];
	memset(store, -1, sizeof(int) * 26);
	for (int i = 0; i < len; i++)
	{
		int pos = str[i] - 97;
		store[pos] = (store[pos] == -1) ? i : store[pos];
	}
	for (int i = 0; i < 26; i++)printf("%d ", store[i]);
	return 0;
}

