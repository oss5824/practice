#pragma warning(disable:4996)
#include <iostream>
#include <stack>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int n = 0, result = 0;
	stack<int >value;
	cin >> n;
	int* store = new int[n];
	for (int i = 0; i < n; i++)cin >> store[i];
	for (int i = 0; i < n; i++)
	{
		if (store[i] != 0)value.push(store[i]);
		else value.pop();
	}
	while(!value.empty())
	{
		result += value.top();
		value.pop();
	}
	printf("%d", result);
	return 0;
}
//#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))