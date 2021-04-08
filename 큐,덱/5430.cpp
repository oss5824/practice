#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
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
		queue<int> q;
		string arr;
		cin >> str;
		cin.ignore();
		cin >> n;
		cin.ignore();
		cin >> arr;
		cin.ignore();
		if (n == 0)
		{
			printf("error\n");
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
			q.push(trans);
		}
		int command_len = str.length();
		int flag = 0;
		for (int j = 0; j < command_len; j++)
		{
			if (str[j] == 'R')
			{
				int vsize = q.size();
				int* store = new int[vsize];
				for (int k = 0; k < vsize; k++)
				{
					store[k] = q.front();
					q.pop();
				}
				for (int k = 0; k < vsize; k++)q.push(store[vsize - 1 - k]);
				delete[] store;
			}
			else if (str[j] == 'D')
			{
				if (q.size() == 0)
				{
					flag = 1;
					break;
				}
				else q.pop();
			}
		}
		if (flag == 1)printf("error");
		else
		{
			printf("[");
			while (!(q.empty()))
			{
				printf("%d", q.front());
				q.pop();
				if (!(q.empty()))printf(",");
				else break;
			}
			printf("]");
		}
		printf("\n");
	}

	return 0;
}