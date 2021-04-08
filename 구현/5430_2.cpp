#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <cmath>
#include <deque>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T = 0;
	cin >> T;
	cin.ignore();
	for (int i = 0; i < T; i++)
	{
		string str;
		int n = 0, count = 0;
		deque<int> q;
		string arr;
		cin >> str;
		cin.ignore();
		cin >> n;
		cin >> arr;
		cin.ignore();
		if (n == 0)
		{
			int len = str.length();
			for (int j = 0; j < len; j++)
			{
				if (str[j] == 'D')
				{
					printf("error\n");
					break;
				}
				else if (j == len - 1)printf("[]\n");
			}
			continue;
		}
		int arr_length = arr.length();
		for (int j = 1; j < arr_length; j++)
		{
			string num = "";
			while (!(arr[j] == ',' || arr[j] == ']'))
			{
				num += arr[j];
				j++;
			}
			int trans = atoi(num.c_str());
			q.push_back(trans);
		}
		int command_len = str.length();
		int flag = 0, turn = 0;
		for (int j = 0; j < command_len; j++)
		{
			if (str[j] == 'R')turn = (turn == 1) ? 0 : 1;
			else if (str[j] == 'D')
			{
				if (q.size() == 0)
				{
					flag = 1;
					break;
				}
				else
				{
					if (turn == 0)q.pop_front();
					else q.pop_back();
				}
			}
		}
		if (flag == 1)printf("error");
		else
		{
			printf("[");
			if (turn == 0)
			{
				while (!(q.empty()))
				{

					printf("%d", q.front());
					q.pop_front();
					if (!(q.empty()))printf(",");
					else break;
				}
			}
			else
			{
				while (!(q.empty()))
				{

					printf("%d", q.back());
					q.pop_back();
					if (!(q.empty()))printf(",");
					else break;
				}
			}
			printf("]");
		}
		printf("\n");
	}

	return 0;
}

