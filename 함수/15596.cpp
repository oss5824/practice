#include <iostream>
#include <vector>
using namespace std;
int n = 0;
long long sum(vector<int>& a)
{
	long long ans = 0;
	for (int i = 0; i < a.size(); i++)ans += a[i];
	return ans;
}
int main()
{
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)v[i] = i + 1;
	printf("%lld", sum(v));
	return 0;
}