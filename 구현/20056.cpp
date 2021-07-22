#include<iostream>
#include<vector>
using namespace std;
int N, M, K, Map[51][51];
vector<pair<pair<int, int>, pair<pair<int, int>, int>>>v;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 }, dy[8] = { -1,-1,0,1,1,1,0,-1 };
pair<int, int>next_pos(int x, int y, int d, int s)
{
	s = s % N;
	while(s--) {
		x += dx[d]; y += dy[d]; 
		if (x == 0)x = N; else if (x == N + 1)x = 1;
		if (y == 0)y = N; else if (y == N + 1)y = 1;
	}
	return { x,y };
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	while (M--) { int r, c, m, s, d; cin >> r >> c >> m >> s >> d; v.push_back({ {c,r},{{m,s},d} }); }
	
	while (K--) {
		vector<pair<pair<int, int>, int>>result[51][51];
		for (pair<pair<int, int>, pair<pair<int, int>, int>>p : v) {
			int x = p.first.first, y = p.first.second;
			int m = p.second.first.first, s = p.second.first.second, d = p.second.second;

			pair<int, int>next = next_pos(x, y, d, s);
			result[next.second][next.first].push_back({ {m,s},d });
		}
		v.clear();
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (result[i][j].size() == 0)continue;
				else if (result[i][j].size() == 1)v.push_back({ {j,i},result[i][j][0] });
				else {
					int m = 0, s = 0, cnt = 0, start = 1;
					for (pair<pair<int, int>, int>p : result[i][j]) {
						m += p.first.first; s += p.first.second;
						if (p.second % 2 == 0)cnt++;
					}
					m = m / 5; if (m == 0)continue;
					s = s / result[i][j].size();
					if (cnt == 0 || cnt == result[i][j].size())start = 0;
					for (int k = start; k < 8; k += 2) v.push_back({ {j,i},{{m,s},k} });			
				}
			}
		}
	}
	int sum=0;
	for (int i = 0; i < v.size(); i++)sum += v[i].second.first.first;
	cout << sum;
	return 0;
}
