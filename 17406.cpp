#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
#define INF 987654321
using namespace std;
int N, M, K, cnt, result = INF;
int Map[51][51];
bool visit[7];
vector<int>v;
vector<int>store[720];
vector<pair<pair<int, int>, int>>input_rotate;
void order(int num)
{
	if (v.size() == K) { store[cnt++] = v; return; }
	for (int i = 1; i <= K; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			v.push_back(i);
			order(i);
			v.pop_back();
			visit[i] = false;
		}
	}
}
void rotate(int startX, int startY, int endX, int endY)
{
	int num = endY - startY + 1;
	num /= 2;
	while (num--) {
		int x = startX, y = startY;
		int len = endY - startY, value = Map[startY][startX];
		for (int i = 0; i < len; i++) { Map[y][x] = Map[y + 1][x]; y++; };
		len = endX - startX;
		for (int i = 0; i < len; i++) { Map[y][x] = Map[y][x + 1]; x++; };
		len = endY - startY;
		for (int i = 0; i < len; i++) { Map[y][x] = Map[y - 1][x]; y--; };
		len = endX - startX;
		for (int i = 0; i < len - 1; i++) { Map[y][x] = Map[y][x - 1]; x--; };
		Map[y][x] = value;
		startX++; startY++;
		endX--; endY--;
	}
}
int check()
{
	int result_sum = INF;
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		for (int j = 1; j <= M; j++)sum += Map[i][j];
		result_sum = min(result_sum, sum);
	}
	return result_sum;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> K; order(1); input_rotate.assign(K + 1, {});
	for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)cin >> Map[i][j];
	for (int i = 1; i <= K; i++)cin >> input_rotate[i].first.second >> input_rotate[i].first.first >> input_rotate[i].second;
	for (int i = 0; i < cnt; i++)
	{
		int backUpMap[51][51]; memcpy(backUpMap, Map, sizeof(Map));
		for (int j = 0; j < K; j++)
		{
			int x = input_rotate[store[i][j]].first.first, y = input_rotate[store[i][j]].first.second, diff = input_rotate[store[i][j]].second;
			rotate(x - diff, y - diff, x + diff, y + diff);
		}
		result = min(result, check());
		memcpy(Map, backUpMap, sizeof(Map));
	}cout << result;
	return 0;
}

