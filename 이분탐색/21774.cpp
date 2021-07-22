#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int N, Q;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> Q;
	cin.ignore();
	string s;
	vector<long long>v1, v2, v3, v4, v5, v6;
	while (N--) {
		getline(cin, s);
		int log = s.back() - '0';
		s.erase(--s.end()); s.erase(--s.end()); s.erase(16, 1); s.erase(13, 1); s.erase(10, 1), s.erase(7, 1); s.erase(4, 1);
		long long val = stoll(s);
		if (log == 1)v1.push_back(val); else if (log == 2)v2.push_back(val); else if (log == 3)v3.push_back(val);
		else if (log == 4)v4.push_back(val); else if (log == 5)v5.push_back(val); else if (log == 6)v6.push_back(val);
	}
	while (Q--) {
		getline(cin, s);
		string start = s.substr(0, 19), end = s.substr(20, 19);
		start.erase(16, 1); start.erase(13, 1); start.erase(10, 1), start.erase(7, 1); start.erase(4, 1);
		end.erase(16, 1); end.erase(13, 1); end.erase(10, 1), end.erase(7, 1); end.erase(4, 1);
		long long start_val = stoll(start), end_val = stoll(end);
		int log = s.back() - '0', sum = 0;
		if (log <= 1) {
			sum += upper_bound(v1.begin(), v1.end(), end_val) - lower_bound(v1.begin(), v1.end(), start_val);
		}
		if (log <= 2) {
			sum += upper_bound(v2.begin(), v2.end(), end_val) - lower_bound(v2.begin(), v2.end(), start_val);
		}
		if (log <= 3) {
			sum += upper_bound(v3.begin(), v3.end(), end_val) - lower_bound(v3.begin(), v3.end(), start_val);
		}
		if (log <= 4) {
			sum += upper_bound(v4.begin(), v4.end(), end_val) - lower_bound(v4.begin(), v4.end(), start_val);
		}
		if (log <= 5) {
			sum += upper_bound(v5.begin(), v5.end(), end_val) - lower_bound(v5.begin(), v5.end(), start_val);
		}
		if (log <= 6) {
			sum += upper_bound(v6.begin(), v6.end(), end_val) - lower_bound(v6.begin(), v6.end(), start_val);
		}
		cout << sum << "\n";
	}
	return 0;
}