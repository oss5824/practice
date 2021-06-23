#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		string result = s;
		int count = 0;
		do {
			if (count == 0) { count++; continue; }
			count++;
			break;
		} while (next_permutation(s.begin(), s.end()));
		if (count == 1)cout << result << "\n"; else cout << s << "\n";
	}
;	return 0;
}
