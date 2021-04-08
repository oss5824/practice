#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
#define INF 987654321
using namespace std;
int N, Map[20][20], result;
vector<int>v;
vector<int>store[1024];
int cnt = 0;
void solve(int num)
{
	if (v.size() == 5) { store[cnt] = v; cnt++; return; }
	for (int i = 0; i < 4; i++)
	{
		v.push_back(i);
		solve(i);
		v.pop_back();
	}
}
void push_block(int direction)
{
	//0À§1¿À2¾Æ3¿Þ
	if (direction == 0) {
		for (int i = 0; i < N; i++){
			vector<int>tmp;
			for (int j = 0; j < N; j++)if (Map[j][i] != 0)tmp.push_back(Map[j][i]);
			int len = tmp.size(); for (int j = 0; j < N; j++) Map[j][i] = (j < len) ? tmp[j] : 0;
		}
	}
	else if (direction == 1) {
		for (int i = 0; i < N; i++) {
			vector<int>tmp;
			for (int j = N - 1; j >= 0; j--)if (Map[i][j] != 0)tmp.push_back(Map[i][j]);
			int len = tmp.size(); for (int j = N - 1, k = 0; j >= 0; j--, k++) Map[i][j] = (k < len) ? tmp[k] : 0;
		}
	}
	else if (direction == 2) {
		for (int i = 0; i < N; i++) {
			vector<int>tmp;
			for (int j = N - 1; j >= 0; j--)if (Map[j][i] != 0)tmp.push_back(Map[j][i]);
			int len = tmp.size(); for (int j = N - 1, k = 0; j >= 0; j--, k++) Map[j][i] = (k < len) ? tmp[k] : 0;
		}
	}
	else if (direction == 3) {
		for (int i = 0; i < N; i++) {
			vector<int>tmp;
			for (int j = 0; j < N; j++)if (Map[i][j] != 0)tmp.push_back(Map[i][j]);
			int len = tmp.size(); for (int j = 0; j < N; j++) Map[i][j] = (j < len) ? tmp[j] : 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		int start = 0; vector<int>tmp;
		if (direction == 0){
			int start = 0;
			while (start < N){
				if (Map[start][i] == 0) { start++; continue; }
				if (start == N - 1) { tmp.push_back(Map[start][i]); break; }
				if (Map[start][i] == Map[start + 1][i]) { tmp.push_back(Map[start][i] * 2); start += 2; }
				else { tmp.push_back(Map[start][i]); start++; }
			}
			int len = tmp.size(); for (int j = 0; j < N; j++) Map[j][i] = (j < len) ? tmp[j] : 0;
		}
		else if (direction == 1){
			int start = N - 1;
			while (start >= 0){
				if (Map[i][start] == 0) { start--; continue; }
				if (start == 0) { tmp.push_back(Map[i][start]); break; }
				if (Map[i][start] == Map[i][start - 1]) { tmp.push_back(Map[i][start] * 2); start -= 2; }
				else { tmp.push_back(Map[i][start]); start--; }
			}
			int len = tmp.size(); for (int j = N - 1, k = 0; j >= 0; j--, k++) Map[i][j] = (k < len) ? tmp[k] : 0;
		}
		else if (direction == 2){
			int start = N - 1;
			while (start >= 0){
				if (Map[start][i] == 0) { start--; continue; }
				if (start == 0) { tmp.push_back(Map[start][i]); break; }
				if (Map[start][i] == Map[start - 1][i]) { tmp.push_back(Map[start][i] * 2); start -= 2; }
				else { tmp.push_back(Map[start][i]); start--; }
			}
			int len = tmp.size(); for (int j = N - 1, k = 0; j >= 0; j--, k++) Map[j][i] = (k < len) ? tmp[k] : 0;
		}
		else if (direction == 3) {
			int start = 0;
			while (start < N) {
				if (Map[i][start] == 0) { start++; continue; }
				if (start == N-1) { tmp.push_back(Map[i][start]); break; }
				if (Map[i][start] == Map[i][start + 1]) { tmp.push_back(Map[i][start] * 2); start += 2; }
				else { tmp.push_back(Map[i][start]); start++; }
			}
			int len = tmp.size(); for (int j = 0; j < N; j++) Map[i][j] = (j < len) ? tmp[j] : 0;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	solve(0); cin >> N;
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)cin >> Map[i][j];
	for (int i = 0; i < cnt; i++)
	{
		int backUpMap[20][20]; memcpy(backUpMap, Map, sizeof(Map));
		for (int j = 0; j < 5; j++)push_block(store[i][j]);
		int max_value = 0;
		for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)max_value = max(Map[i][j], max_value);
		result = max(max_value, result);
		memcpy(Map, backUpMap, sizeof(Map));
	}cout << result;
	return 0;
}

