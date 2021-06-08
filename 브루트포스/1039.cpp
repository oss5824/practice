#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF INT_MAX

using namespace std;
bool visit[1000000][12];
int N, K, result;
bool resultK;
void bfs()
{
	queue<pair<int, int>>q; q.push({ N,0 }); visit[N][0] = true;
	while (!q.empty()) {
		int cur = q.front().first, curK = q.front().second; q.pop();
		string s = to_string(cur); int len = s.length();
		if (curK == K) { result = max(result, cur); resultK = true; }
		if (curK > K)break;
		for (int i = 0; i < len - 1; i++)
			for (int j = i + 1; j < len; j++){
				string tmp = s;
				swap(tmp[i], tmp[j]);
				if (tmp[0] == '0')continue;
				int val = stoi(tmp);
				if (!visit[val][curK + 1]) {
					visit[val][curK + 1] = true; q.push({ val,curK + 1 });
				}
			}
	}
	if (resultK)cout << result;
	else cout << "-1";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> K;
	bfs();
	return 0;
}


