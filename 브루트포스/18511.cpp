#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s, v, tmp = "", res = "0";
int k;
void solve(int n)
{
	if (tmp != "" && stoi(tmp) > stoi(s)) return;
	if (tmp != "" && stoi(tmp) > stoi(res))res = tmp;
	for (int i = 0; i < k; i++) {
		tmp.push_back(v[i]);
		solve(i);
		tmp.pop_back();
	}
}
int main(){
	cin.tie(NULL);ios::sync_with_stdio(false);
	cin >> s >> k; for (int i = 0, a; i < k; i++)cin >> a, v.push_back(a + '0');
	sort(v.begin(), v.end());
	solve(0);
	cout << res;
}
