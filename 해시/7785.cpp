#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
map<string, int>m;
vector<string>res;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n; cin >> n; string s1, s2;
	while (n--) { cin >> s1 >> s2; if (s2 == "enter")m[s1] = 1; else m[s1] = 0; }
	vector<pair<string, int>>v(m.begin(), m.end());
	for (pair<string, int>arr : v) { if (arr.second == 1)res.push_back(arr.first); }
	sort(res.begin(), res.end(), greater<string>());
	for (string s : res)cout << s << "\n";
	return 0;
}