#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int N, M, v[7];
set<vector<int>>st;
vector<int>vec;
void solve(int n)
{
	if (vec.size() == M) { for (int i : vec)cout << i << " "; cout << "\n"; return; }
	for (int i = n; i < N; i++) {
		vec.push_back(v[i]);
		if (st.count(vec) == 0) { st.insert(vec); solve(n); }
		vec.pop_back();
	}
}
int main()
{
	cin >> N >> M; for (int i = 0; i < N; i++)cin >> v[i];
	sort(v, v + N); solve(0);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);