#include <iostream>
#include <map>
#include <cstring>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, res = 0; string str;
	cin >> n >> m; map<string, int>arr;
	for (int i = 1; i <= n; i++) { cin >> str; arr[str] = i; }
	for (int i = 0; i < m; i++) { cin >> str; if (arr[str] != 0)res++; }
	cout << res;
	return 0;
}
