#include<iostream>
#include<map>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int t, n; cin >> t;
	while (t--) {
		cin >> n; map<int, int>m; int arr[11], max = 0, idx = 1, all = 0;
		for (int i = 1; i <= n; i++){
			cin >> arr[i]; if (arr[i] > max) { max = arr[i]; idx = i; }
			m[arr[i]]++; all += arr[i];
		}
		if (m[arr[idx]] > 1)cout << "no winner\n";
		else{
			string s = ((double)arr[idx] / (double)all > 0.5) ? "majority winner" : "minority winner";
			cout << s << " " << idx << "\n";
		}
	}
	return 0;
}