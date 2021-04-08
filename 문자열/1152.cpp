#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000001
using namespace std;
int main()
{
	int count = 0;
	char str[SIZE];
	cin.getline(str, SIZE);
	char* token = strtok(str, " \n");
	while (token)
	{
		token = strtok(NULL, " \n");
		count++;
	}
	printf("%d", count);
	return 0;
}

