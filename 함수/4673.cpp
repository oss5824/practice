#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	bool* arr = new bool[10500];
	memset(arr, false, sizeof(bool) * 10500);
	for (int i = 1; i < 10000; i++)
	{
		int start = i;
		while (start <= 10000 && !arr[start])
		{
			arr[start] = (i == start) ? arr[start] : true;
			if (start < 10)start = start * 2;
			else if (start < 100)
			{
				int ten = start / 10;
				int one = start % 10;
				start = start + ten + one;
			}
			else if (start < 1000)
			{
				int hun = start / 100;
				int value = start - 100 * hun;
				int ten = value / 10;
				int one = value % 10;
				start = start + hun + ten + one;
			}
			else
			{
				int tho = start / 1000;
				int val = start - tho * 1000;
				int hun = val / 100;
				int value = val - 100 * hun;
				int ten = value / 10;
				int one = value % 10;
				start = start + tho + hun + ten + one;
			}
		}
	}
	for (int i = 1; i < 10000; i++)if (!arr[i])printf("%d\n", i);
	return 0;
}