#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000000
using namespace std;
int main()
{
	char* str = new char[SIZE];
	int store[26] = { 0, };
	cin >> str;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		int num = (str[i] <= 90) ? str[i] - 65 : str[i] - 97;
		store[num]++;
	}
	int max = store[0];
	int position = 0, check = 0;
	for (int i = 1; i < 26; i++)max = (max >= store[i]) ? max : store[i];
	for (int i = 0; i < 26; i++)
	{
		check = (max == store[i]) ? check + 1 : check;
		position = (max == store[i]) ? i : position;
	}
	if (check != 1)cout << "?";
	else cout << (char)(65 + position) << endl;

	return 0;
}

