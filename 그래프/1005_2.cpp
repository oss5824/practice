#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int T, n, m, a, b, c;
int arr[1001], level[1001], result[1001];
vector<int>* v;
int main(){
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--){
		cin >> n >> m; memset(arr, 0, sizeof(arr)); memset(level, 0, sizeof(level)); memset(result, 0, sizeof(result));
		v = new vector<int>[n + 1];
		for (int i = 1; i <= n; i++) { cin >> arr[i]; result[i] = arr[i]; }
		for (int i = 1; i <= m; i++) { cin >> a >> b; v[a].push_back(b); level[b]++; }
		cin >> c;
		queue<int>q;
		for (int i = 1; i <= n; i++)if (level[i] == 0)q.push(i);
		while (1) {
			int cur = q.front(); q.pop();
			for (int next : v[cur]) {
				if (--level[next] == 0)q.push(next);
				result[next] = max(result[next], result[cur] + arr[next]);
			}
			if (level[c] == 0) { cout << result[c] << "\n"; break; }
		}
	}
	return 0;
}