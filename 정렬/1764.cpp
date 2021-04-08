#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<string, int>arr;
vector<string>v;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m; string s; cin >> n >> m; while (n--) { cin >> s; arr[s]++; }while (m--) { cin >> s; if (arr[s] != 0)v.push_back(s); }
	sort(v.begin(), v.end()); cout << v.size() << "\n"; for (string str : v)cout << str << "\n";
	return 0;
}