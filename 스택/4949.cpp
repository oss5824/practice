#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <stack>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	while(1)
	{
		int flag = 1;
		stack<char>value;
		string str;
		getline(cin, str);
		if (str.length() == 1 && str[0] == '.')break;
		int len = str.length();
		for (int j = 0; j < len; j++)
		{
			if (str[j] == '(' || str[j] == '[')value.push(str[j]);
			else if (str[j] == ')')
			{
				if(value.empty())
				{
					flag = 0;
					break;
				}
				if (value.top() == '(')value.pop();
				else 
				{
					flag = 0;
					break;
				}
			}
			else if (str[j] == ']')
			{
				if (value.empty())
				{
					flag = 0;
					break;
				}
				if (value.top() == '[' && !value.empty())value.pop();
				else
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag == 1 && value.empty())printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
//#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))