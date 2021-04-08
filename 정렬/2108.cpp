#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<int>v(n);
	double res = 0;
	int max_value = 0, result = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		res += (double)v[i];
	}
	printf("%d\n", (int)round(res / n));
	sort(v.begin(), v.end());
	printf("%d\n", v[n / 2]);
	int store[8001] = { 0, };
	bool b = false;
	for (int i = 0; i < n; i++)max_value = max(++store[4000 + v[i]], max_value);
	for (int i = 0; i <= 4000 + v[n - 1]; i++)
	{
		if (max_value == store[i] && b)
		{
			result = i - 4000;
			break;
		}
		if (max_value == store[i])
		{
			result = i - 4000;
			b = true;
		}
	}
	printf("%d\n", result);
	printf("%d\n", v[n - 1] - v[0]);
	return 0;
}