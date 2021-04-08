#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a >= b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
		if (a == 1 || b == 1)printf("%d\n", b);
		else if (a == b || b % a == 0)printf("%d\n", b);
		else
		{
			unsigned long long res = a * b;
			int start = 2;
			int value = 0;
			while (1)
			{
				if (a % start == 0 && b % start == 0)value = start;
				start++;
				if (start > b)break;
			}
			if (value == 0)printf("%llu\n", res);
			else printf("%llu\n", res / value);
		}
	}
	return 0;
}