#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
bool arr[4000001];
vector<int>v;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, result = 0, s = 0, e = 0, sum = 0;
	cin >> n;
	memset(arr, false, sizeof(arr));
	int len = (int)ceil(sqrt(n));
	for (int i = 2; i <= len; i++)if (!arr[i])for (int j = i * i; j <= n; j += i)arr[j] = true;
	for (int i = 2; i <= n; i++)if (!arr[i])v.push_back(i);
	while (1)
	{
		if (sum >= n)sum -= v[s++];
		else if (e == v.size())break;
		else sum += v[e++];
		if (sum == n)result++;
	}
	printf("%d", result);
	return 0;
}