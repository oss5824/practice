#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int t, n; cin >> t;
	while (t--) {
		cin >> n; double res = 0;
		for (int i = 2; i <= n; i++)res += log10(i);
		cout << (int)(res + 1) << "\n";
	}
	return 0;
}