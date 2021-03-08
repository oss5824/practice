#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int T, n, m, a, b, c;
int arr[1001], level[1001], result[1001];
vector<int>* v;
void bfs()
{
	queue<int>q; int max_val = 0;
	for (int i = 1; i <= n; i++)if (level[i] == 0) { q.push(i); max_val = max(arr[i], max_val); }
	result[0] = max_val;
	while (!q.empty()){
		int cur = q.front(), len = v[cur].size(), cur_cost = arr[cur]; q.pop();
		int next_cost = 0;
		for (int next : v[cur])
			if (level[cur] + 1 == level[next]){
				next_cost = max(next_cost, arr[next]);
				q.push(next);
			}
		result[level[cur] + 1] = max(result[level[cur] + 1], result[level[cur]] + next_cost);
	}
}
int main(){
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--){
		cin >> n >> m; memset(arr, 0, sizeof(arr)); memset(level, 0, sizeof(level)); memset(result, 0, sizeof(result));
		v = new vector<int>[n + 1];
		for (int i = 1; i <= n; i++)cin >> arr[i]; 
		for (int i = 1; i <= m; i++) { cin >> a >> b; v[a].push_back(b); level[b] = (level[a] == 0) ? level[b] + 1 : level[a] + 1; }
		bfs();cin >> c;
		(level[c] == 0) ? cout << arr[c] << "\n" : cout << result[level[c] - 1] + arr[c] << "\n";
	}
	return 0;
}