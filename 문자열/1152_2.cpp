#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000000
using namespace std;
int main()
{
	char* str = new char[SIZE];
	char* str_= new char[SIZE];
	int* store = new int[SIZE];
	cin.getline(str, SIZE);
	int count = 0;
	int result = 0;
	strcpy(str_, str);
	memset(store, 0, 4 * SIZE);

	while (1)
	{
;		strcpy(str, str_);
		char* newptr = strtok(str, " ");
		char* startptr = newptr;
		int start = count;
		for (int i = 0; i <= count; i++)
		{
			newptr = strtok(NULL, " ");
			if (i == count - 1)startptr = newptr;
		}
		if (newptr == NULL)break;

		while (newptr != NULL)
		{
			start++;
			if (store[start] == 1)
			{
				newptr = strtok(NULL, " ");
				continue;
			}
			if ((!strcmp(startptr, newptr)) && store[count] == 0)
			{
				store[start] = 1;
				store[count] = 1;
				result++;
			}
			else if (!strcmp(startptr, newptr))store[start] = 1;
			newptr = strtok(NULL, " ");
		}
		if (store[count] == 0)
		{
			store[count] = 1;
			result++;
		}
		count++;
	}
	if (store[count] == 0)result++;
	printf("%d", result);

	return 0;
}

