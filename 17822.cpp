#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
#define INF 987654321
using namespace std;
int N, M, T, result;
int Map[51][51];
bool visit[51][51];
vector<pair<int, int>>v;
void clock(int y)
{
	int value = Map[y][M];
	for (int i = M; i >= 2; i--)Map[y][i] = Map[y][i - 1];
	Map[y][1] = value;
}
void counter_clock(int y)
{
	int value = Map[y][1];
	for (int i = 1; i <= M - 1; i++)Map[y][i] = Map[y][i + 1];
	Map[y][M] = value;
}
double Mean()
{
	int cnt = 0; double sum = 0;
	for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)if (Map[i][j] != 0) { cnt++; sum += (double)Map[i][j]; }
	if (cnt == 0)return 0;
	return sum / cnt;
}
void solve()
{
	v.clear(); memset(visit, false, sizeof(visit));
	bool final_check = false;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (Map[i][j] == 0)continue;
			bool check = false;
			if (i == 1){
				if (j == 1){
					if (Map[1][1] == Map[1][M]) { check = true; if (!visit[1][M]) { v.push_back({ M,1 }); visit[1][M] = true; } }
					if (Map[1][1] == Map[1][2]) { check = true; if (!visit[1][2]) { v.push_back({ 2,1 }); visit[1][2] = true;} }
				}
				else{
					if (Map[1][j] == Map[1][j - 1]) { check = true;  if (!visit[1][j - 1]) { v.push_back({ j - 1,1 }); visit[1][j - 1] = true; } }
					if (Map[1][j] == Map[1][j + 1]) { check = true; if (!visit[1][j + 1]) { v.push_back({ j + 1,1 }); visit[1][j + 1] = true; }}
				}
				if (Map[1][j] == Map[2][j]) { check = true; if (!visit[2][j]) { v.push_back({ j,2 }); visit[2][j] = true; } }
			}
			else if (i == N) {
				if (j == 1){
					if (Map[N][1] == Map[N][M]) { check = true; if (!visit[N][M]) { v.push_back({ M,N }); visit[N][M] = true; } }
					if (Map[N][1] == Map[N][2]) { check = true; if (!visit[N][2]) { v.push_back({ 2,N }); visit[N][2] = true; } }
				}
				else{
					if (Map[N][j] == Map[N][j - 1]) { check = true; if (!visit[N][j - 1]) { v.push_back({ j - 1,N }); visit[N][j - 1] = true; } }
					if (Map[N][j] == Map[N][j + 1]) { check = true; if (!visit[N][j + 1]) { v.push_back({ j + 1,N }); visit[N][j + 1] = true; } }
				}
				if (Map[N][j] == Map[N - 1][j]) { check = true; if (!visit[N - 1][j]) { v.push_back({ j,N - 1 }); visit[N - 1][j] = true; } }
			}
			else {
				if (j == 1) {
					if (Map[i][1] == Map[i][M]) { check = true; if (!visit[i][M]) { v.push_back({ M,i }); visit[i][M] = true; } }
					if (Map[i][1] == Map[i][2]) { check = true; if (!visit[i][2]) { v.push_back({ 2,i }); visit[i][2] = true; } }
				}
				else {
					if (Map[i][j] == Map[i][j - 1]) { check = true; if (!visit[i][j - 1]) { v.push_back({ j - 1,i }); visit[i][j - 1] = true; } }
					if (Map[i][j] == Map[i][j + 1]) { check = true; if (!visit[i][j + 1]) { v.push_back({ j + 1,i }); visit[i][j + 1] = true; } }
				}
				if (Map[i][j] == Map[i - 1][j]) { check = true; if (!visit[i - 1][j]) { v.push_back({ j,i - 1 }); visit[i - 1][j] = true; } }
				if (Map[i][j] == Map[i + 1][j]) { check = true; if (!visit[i + 1][j]) { v.push_back({ j,i + 1 }); visit[i + 1][j] = true; } }
			}
			if (check) { if (!visit[i][j]) { v.push_back({ j,i }); visit[i][j] = true; } }
			if (check)final_check = true;
		}
	}
	if (!final_check)
	{
		double mean = Mean();
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (Map[i][j] != 0)
				{
					if (Map[i][j] > mean)Map[i][j]--; else if (Map[i][j] < mean)Map[i][j]++;
				}
	}
	else
	{
		for (pair<int, int>p : v)
		{
			int x = p.first, y = p.second;
			Map[y][x] = 0;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)cin >> Map[i][j];
	while (T--)
	{
		int num, counter_clockwise, count;
		cin >> num >> counter_clockwise >> count; 
		for (int i = num; i <= N; i += num)
		{
			if (counter_clockwise == 1)for (int j = 0; j < count; j++)counter_clock(i);
			else for (int j = 0; j < count; j++)clock(i);
		}
		solve();
	}for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)result += Map[i][j];
	cout << result << "\n";
	return 0;
}

