#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int t, k, m, p, a, b;
vector<int>v[1001]; pair<int, int>cnt[1001]; int lv[1001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		queue <int>q; cin >> k >> m >> p;
		for (int i = 0; i <= 1000; i++) { v[i].clear(); cnt[i] = { 0,0 }; lv[i] = 0; }
		while (p--) { cin >> a >> b; lv[b]++; v[a].push_back(b); }
		for (int i = 1; i <= m; i++)if (lv[i] == 0) { q.push(i); cnt[i] = { 1,1 }; }
		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			if (cur == m) { cout << k << " " << cnt[cur].first << "\n"; break; }
			for (int next : v[cur]) {
				if (cnt[next].second == 0) { cnt[next] = cnt[cur]; }
				else {
					if (cnt[next].first == cnt[cur].first) { cnt[next].second = 2; }
					else if (cnt[next].first < cnt[cur].first) { cnt[next].first = cnt[cur].first; cnt[next].second = 1; }
				}
				if (--lv[next] == 0){
					if (cnt[next].second == 2) { cnt[next].first++; cnt[next].second = 1; }
					q.push(next);
				}
			}
		}
	}
	return 0;
}


