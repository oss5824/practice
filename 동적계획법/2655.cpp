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
int N;
vector<pair<pair<int, int>, pair<int, int>>>v;
int DP[101];
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) { int a, b, c; cin >> a >> b >> c; v.push_back({ {c,a},{b,i} }); }
	sort(v.begin(), v.end());
	
	for (int i = 0; i < N; i++)
	{
		DP[i] = v[i].second.first;
		for (int j = 0; j <= i; j++) {
			if (v[i].first.second > v[j].first.second) {
				DP[i] = max(DP[i], DP[j] + v[i].second.first);
			}
		}
	}
	int val = *max_element(DP, DP + N), idx = N - 1;
	stack<int>st;
	while (idx >= 0) {
		if (val == DP[idx]) {
			st.push(v[idx].second.second);
			val = val - v[idx].second.first;
		}
		idx--;
	}
	cout << st.size() << "\n";
	while (!st.empty()) { cout << st.top() << "\n"; st.pop(); }
;	return 0;
}

