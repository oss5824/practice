#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int N, M, d[50001], p[17][50001];
vector<int>v[50001];
int getP(int a, int b) {
	while (d[a] != d[b] && d[a] != 0) { a = p[(int)log2(d[a] - d[b])][a]; }
	if (a == b)return a;
	for (int i = 16; i >= 0; i--) {
		if (p[i][a] != p[i][b]) { a = p[i][a]; b = p[i][b]; }
	}return p[0][a];
}
int main(){
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0, a, b; i < N - 1; i++) {
		cin >> a >> b; v[a].push_back(b); v[b].push_back(a);
	}cin >> M;
	queue<int>q; q.push(1); d[1] = 1;
	while (!q.empty()) {
		int c = q.front(); q.pop();
		for (int n : v[c]) { if (!d[n]) { d[n] = d[c] + 1; p[0][n] = c; q.push(n); } }
	}
	for (int i = 1; i <= 17; i++) {
		for (int j = 1; j <= N; j++) { if (p[i - 1][j]) p[i][j] = p[i - 1][p[i - 1][j]]; }
	}
	while (M--) {
		int a, b; cin >> a >> b;
		if (d[a] < d[b])swap(a, b);
		cout << getP(a, b) << "\n";
	}
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);


