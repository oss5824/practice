#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
pair<int, int>v[100001];
int result[100001], pos;
set<int>st;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int N; cin >> N; for (int i = 1; i <= N; i++)cin >> v[i].first >> v[i].second;
	sort(v + 1, v + N + 1);
	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>,
		greater<pair<pair<int, int>, int>>>q;
	for (int i = 1; i <= N; i++) {
		int start = v[i].first, end = v[i].second, sz = q.size();
		while (!q.empty() && q.top().first.first <= start) { st.insert(q.top().second); q.pop(); }
		if (st.empty()) { q.push({ {end,start},++pos }); result[pos]++; }
		else { q.push({ {end,start}, *st.begin() }); result[*st.begin()]++; st.erase(st.begin()); }
	}
	cout << pos << "\n";
	for (int i = 1; i <= pos; i++)cout << result[i] << " ";
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);