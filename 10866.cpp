#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <queue>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n = 0;
	queue<int >value;
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
		if (!strcmp("push_front", command))
		{
			int len = value.size();
			value.push(num);
			for (int i = 0; i < len; i++)
			{
				value.push(value.front());
				value.pop();
			}
		}
		else if (!strcmp("push_back", command))value.push(num);
		else if (!strcmp("front", command))
		{
			if (value.empty())printf("-1\n");
			else printf("%d\n", value.front());
		}
		else if (!strcmp("back", command))
		{
			if (value.empty())printf("-1\n");
			else printf("%d\n", value.back());
		}
		else if (!strcmp("size", command))printf("%d\n", value.size());
		else if (!strcmp("pop_front", command))
		{
			if (value.empty())printf("-1\n");
			else
			{
				printf("%d\n", value.front());
				value.pop();
			}
		}
		else if (!strcmp("pop_back", command))
		{
			if (value.empty())printf("-1\n");
			else
			{
				int len = value.size() - 1;
				for (int i = 0; i < len; i++)
				{
					value.push(value.front());
					value.pop();
				}
				printf("%d\n", value.front());
				value.pop();
			}
		}
		else if (!strcmp("empty", command))printf("%d\n", value.empty());
	}
	return 0;
}