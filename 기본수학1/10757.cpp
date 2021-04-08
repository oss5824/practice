#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int main()
{
	char a[10002];
	char b[10002];
	char c[10003] = { 0, };
	int up = 0;
	deque<char>aq;
	deque<char>bq;
	cin >> a >> b;
	int len_a = strlen(a);
	int len_b = strlen(b);
	int len = 0;
	for (int i = len_a - 1; i >= 0; i--)aq.push_back(a[i]);
	for (int i = len_b - 1; i >= 0; i--)bq.push_back(b[i]);
	if (len_a > len_b)for (int i = len_b; i < len_a; i++)bq.push_back('0');
	else if (len_a < len_b)for (int i = len_a; i < len_b; i++)aq.push_back('0');
	if (len_a >= len_b)len = len_a;
	else len = len_b;
	for (int i = 0; i <= len; i++)
	{
		if (i == len)
		{
			if (up == 1)c[i] = 49;
			else len = len - 1;
			break;
		}
		int x = aq.front() - 48, y = bq.front() - 48;
		aq.pop_front(), bq.pop_front();
		int value = x + y + up;
		if (value >= 10)
		{
			up = 1;
			value = value - 10;
		}
		else up = 0;
		c[i] = value + 48;
		if (i > len_a && i > len_b)break;
	}
	for (int i = len; i >= 0; i--)printf("%c", c[i]);
	return 0;
}