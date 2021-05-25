#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<limits.h>
#define INF INT_MAX
using namespace std;
pair<int, int>p[8];
priority_queue<int, vector<int>, greater<int>>q;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	for (int i = 0; i < 8; i++) { cin >> p[i].first; p[i].second = i + 1; }
	sort(p, p + 8, greater<pair<int, int>>());
	int sum = 0;
	for (int i = 0; i < 5; i++) { sum += p[i].first; q.push(p[i].second); }
	cout << sum << "\n";
	while (!q.empty()) { cout << q.top() << " "; q.pop(); }
	return 0;
}