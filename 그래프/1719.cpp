#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<set>
#define INF 1e9
using namespace std;
int N, M;
int Map[201][201];
string Route[201][201];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (i == j)Map[i][j] = 0;
			else { Map[i][j] = INF; }
		}
	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (Map[a][b] > c) { Map[a][b] = c; Route[a][b] = to_string(b); Route[a][b] += ' '; }
		if (Map[b][a] > c) { Map[b][a] = c; Route[b][a] = to_string(a); Route[b][a] += ' '; }
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (Map[i][j] > Map[i][k] + Map[k][j]) {
					Map[i][j] = Map[i][k] + Map[k][j];
					Route[i][j] = Route[i][k] + Route[k][j];
				}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Route[i][j] == "")cout << "- "; 
			else {
				int idx = Route[i][j].find(' ', 0);
				cout << Route[i][j].substr(0, idx) << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}

