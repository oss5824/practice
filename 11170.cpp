#include<iostream>
#include <string>
using namespace std;
int arr[1000001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, t; cin >> t;
	for (int i = 0; i <= 1000000; i++)arr[i] = i;
	while (t--) {
		cin >> n >> m; int res = 0;
		for (int i = n; i <= m; i++) {
			string ns = to_string(i); int len = ns.length();
			for (int j = 0; j < len; j++)if (ns[j] == '0')res++;
		}
		cout << res << "\n";
	}
	return 0;
}