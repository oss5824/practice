#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <stack>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int n = 0;
	stack<int >value;
	cin >> n;
	char** str = new char* [n];
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		str[i] = new char[100];
		cin.getline(str[i], 100);
	}
	for (int i = 0; i < n; i++)
	{
		int num = 0;
		char command[100] = { 0, };
		char* token = strtok(str[i], " \n");
		strcpy(command, token);
		token = strtok(NULL, " \n");
		if (token != NULL)num = atoi(token);
		if (!strcmp("push", command))value.push(num);
		else if (!strcmp("top", command))
		{
			if (value.empty())cout << "-1" << endl;
			else cout << value.top() << endl;
		}
		else if (!strcmp("size", command))cout << value.size() << endl;
		else if (!strcmp("pop", command))
		{
			if (value.empty())cout << "-1" << endl;
			else
			{
				cout << value.top() << endl;
				value.pop();
			}
		}
		else if (!strcmp("empty", command))cout << value.empty() << endl;
	}
	return 0;
}
//#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))