#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, len;
string s, tmp;
set<string>check;
bool* visit;

void solve(int num)
{
	if (tmp.size() == len) { cout << tmp << "\n"; return; }
	for (int i = num; i < len; i++) {
		if (!visit[i]) {
			visit[i] = true;
			tmp.push_back(s[i]);
			if (check.count(tmp) == 0) { check.insert(tmp); solve(num); }
			tmp.pop_back();
			visit[i] = false;
		}
	}
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	while (N--) {
		cin >> s; len = s.size(); visit = new bool[len]; check.clear(); tmp.clear(); sort(s.begin(), s.end());
		for (int i = 0; i < len; i++)visit[i] = false; solve(0);
	}
	return 0;
}

