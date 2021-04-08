#include <iostream>
using namespace std;
int main()
{
	int n = 0, count = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int start = i;
		if (i < 100)count++;
		else if (start < 1000)
		{
			int hun = start / 100;
			int value = start - 100 * hun;
			int ten = value / 10;
			int one = value % 10;
			if (ten - one == hun - ten)count++;
		}
	}
	printf("%d", count);
	return 0;
}