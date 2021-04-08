#include <iostream>
using namespace std;
int main()
{
	int store[42] = { 0, }, arr[10], count = 0;
	for (int i = 0; i < 10; i++)cin >> arr[i];
	for (int i = 0; i < 10; i++)store[arr[i] % 42]++;
	for (int i = 0; i < 42; i++)if (store[i])count++;
	printf("%d", count);
	return 0;
}