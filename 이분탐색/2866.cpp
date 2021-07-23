#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int N, M, cnt;
string str[1000], s[1000];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> str[i];
	for (int j = 0; j < M; j++)for (int i = 0; i < N; i++) { s[j].push_back(str[i][j]);}
	while (N--) {
		map<string, int>m;
		for (int i = 0; i < M; i++) { s[i].erase(0, 1); m[s[i]]++;}
		for (auto pos = m.begin(); pos != m.end(); pos++) {
			if ((*pos).second != 1) { cout << cnt; return 0; }
		}cnt++;
	}
	cout << cnt;
	return 0;
}