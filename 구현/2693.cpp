#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int t,a; cin >> t;
	while (t--) {
		int n = 10; vector<int>v;
		while (n--) { cin >> a; v.push_back(a); }
		sort(v.begin(), v.end());
		cout << v[7] << "\n";
	}
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
