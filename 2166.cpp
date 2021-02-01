#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	long long n, a, b, result1 = 0, result2 = 0, result; cin >> n;
	vector<pair<long long, long long>>v;
	for (int i = 0; i < n; i++) { cin >> a >> b; v.push_back({ a,b }); }
	for (int i = 0; i < n - 1; i++)
	{
		result1 += v[i].first * v[i + 1].second;
		result2 += v[i + 1].first * v[i].second;
	}
	result1 += v[n - 1].first * v[0].second; result2 += v[0].first * v[n - 1].second;
	result = llabs(result1 - result2);
	cout << result / 2;
	if (result % 2 == 0)cout << ".0"; else cout << ".5";
	return 0;
}