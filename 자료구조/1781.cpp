#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int N;
vector<pair<int, int>>v;

bool cmp(pair<int, int>a, pair<int, int>b)
{
	if (a.first < b.first)return true;
	else if (a.first > b.first)return false;
	else return a.second < b.second;
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) { cin >> a >> b; v.push_back({ a,b }); }
	sort(v.begin(), v.end(), cmp);
	priority_queue<int, vector<int>, greater<int>>q;
	for (int i = 0; i < N; i++)
	{
		int time = v[i].first, count = v[i].second;
		int size = q.size();
		if (size < time)q.push(count);
		else if (size == time) {
			if (q.top() < count) { q.pop(); q.push(count); }
		}
	}
	int sum = 0;
	while (!q.empty()) { sum += q.top(); q.pop(); }
	cout << sum;
;	return 0;
}
