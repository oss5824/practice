#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a, b, c, len = 0;
	unsigned long long res, l_res;
	cin >> a >> b >> c;
	int arr[10] = { 0, };
	res = a * b * c;
	l_res = res;
	while (l_res > 0)
	{
		l_res /= 10;
		len++;
	}
	len--;
	while (len >= 0)
	{
		unsigned long long l = pow(10, len);
		int d = res / l;
		arr[d]++;
		res = res - d * l;
		len--;
	}
	for (int i = 0; i < 10; i++)printf("%d\n", arr[i]);
	return 0;
}  
