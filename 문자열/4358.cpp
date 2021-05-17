#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#include<limits.h>
#define INF 1e9
using namespace std;
string s;
map<string, double>m;
int main()
{
	cout.tie(NULL);
	cin.tie(NULL); ios::sync_with_stdio(false);
	double cnt = 0;
	while (getline(cin, s)) { m[s]++; cnt++; }
	vector<pair<string, double>>v(m.begin(), m.end());
	sort(v.begin(), v.end());
	cout << fixed;
	cout.precision(4);
	for (auto a : v)
	{
		string b = a.first;
		double c = (a.second * 100) / cnt;
		cout << b << " " << round(c * 10000) / 10000 << "\n";
	}
	return 0;
}