#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	unsigned long long* distance = new unsigned long long[n - 1];
	unsigned long long* price = new unsigned long long[n];
	unsigned long long value = 0, all = 0;
	for (int i = 0; i < n - 1; i++)cin >> distance[i];
	for (int i = 0; i < n; i++)cin >> price[i];
	value = price[0];
	all = value * distance[0];
	for (int i = 1; i < n-1; i++)
	{
		unsigned long long turn = price[i];
		value = min(value, turn);
		all += value * distance[i];
	}
	printf("%llu", all);
	return 0;
}