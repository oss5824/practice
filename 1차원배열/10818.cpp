#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a, n, _min = 1000001, _max = -1000001;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		_min = min(a, _min);
		_max = max(a, _max);
	}
	printf("%d %d", _min, _max);
	return 0;
}