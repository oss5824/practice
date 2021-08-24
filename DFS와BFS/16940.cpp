#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;
int N, idx = 1;
vector<int>v[100001];
int res[100000];
bool visit[100001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; for (int i = 0, a, b; i < N - 1; i++) { cin >> a >> b; v[a].emplace_back(b); v[b].emplace_back(a); }
	for (int i = 0; i < N; i++)cin >> res[i];
	if (res[0] != 1) { cout << 0; return 0; }
	queue<int>q; q.push(1); visit[1] = 1;
	while (!q.empty()) {
		int x = q.front(), cnt = 0; q.pop();
		for (int nx : v[x]) {
			if (visit[nx])continue;
			visit[nx] = 1; cnt++;
		}
		for (int i = idx; i < idx + cnt; i++) {
			if (!visit[res[i]]) { cout << 0; return 0; }
			else q.push(res[i]);
		}idx += cnt;
	}
	cout << "1";
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
