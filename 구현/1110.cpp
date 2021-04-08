#include <iostream>
using namespace std;
int main()
{
	short n, res = 0, count = 0;
	cin >> n;
	res = n;
	while (1)
	{
		short a = res / 10, b = res % 10;
		res = b * 10 + (a + b) % 10;
		count++;
		if (res == n)break;
	}
	printf("%d", count);
	return 0;
}
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
