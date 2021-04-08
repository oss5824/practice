#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<int>v;
bool prime[4000001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, s = 0, e = 0, result = 0; cin >> n; int len = sqrt(n), val = 0;
	for (int i = 2; i <= len; i++) { if (!prime[i]) { for (int j = i * i; j <= n; j += i)prime[j] = true; } }
	for (int i = 2; i <= n; i++)if (!prime[i]) v.push_back(i); len = v.size();
	while (1){
		if (result >= n)result -= v[s++];
		else if (e == len)break;
		else { result += v[e++]; }
		if (result == n)val++;
	}
	cout << val;
	return 0;
}