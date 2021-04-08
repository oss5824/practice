#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int n = 0, count = 0, pm_count = 0, result = 0;
	int arr[51] = { 0, };
	char pm_array[51] = { 0, };
	char store[51] = { 0, };
	char pm_store[51] = { 0, };
	char pm[51] = { 0, };
	cin >> store;
	strcpy(pm_store, store);
	int len = strlen(store);
	char* str = strtok(store, "+-");
	while (str != NULL)
	{
		arr[count++] = atoi(str);
		str = strtok(NULL, " +-\n");
	}
	arr[count] = 0;
	for (int i = 0; i < len; i++)if (pm_store[i] == '-' || pm_store[i] == '+')pm_array[pm_count++] = pm_store[i];
	pm_array[pm_count] = 'x';
	result = arr[0];
	for (int i = 0; i < pm_count;)
	{
		if (pm_array[i] == '-')
		{
			int a = 0;
			result -= arr[i + 1];
			i++;
			while (pm_array[i] == '+' || pm_array[i] == 'x')
			{
				result -= arr[i + 1];
				i++;;
			}
		}
		else
		{
			result += arr[i + 1];
			i++;
		}
	}
	printf("%d", result);
	return 0;
}
