#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <string>
#include <cstring>
#define INF 1e9
using namespace std;
pair<pair<long long, string>, int>M[101][101];
int n, m;
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i != j)M[i][j] = make_pair(make_pair(INF, ""), 1);
			else M[i][j] = make_pair(make_pair(0, ""), 1);
		}
	for (int i = 0; i < m; i++)
	{
		int s, e, dist;
		cin >> s >> e >> dist;
		M[s][e] = (M[s][e].first.first > dist) ? make_pair(make_pair((long long)dist, to_string(s) + " "
			+ to_string(e) + " "), 2) : M[s][e];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
			{
				long long a = M[j][k].first.first, b = M[j][i].first.first, c = M[i][k].first.first;
				int y = M[j][i].second;
				string w = M[i][k].first.second; char ch[100]; strcpy(ch, w.c_str());
				char* rem = NULL; strtok_s(ch, " ", &rem); strcpy(ch, rem);
				string p(ch); string s = M[j][i].first.second + p;
				M[j][k] = (a > b + c) ? make_pair(make_pair(b + c, s), y + 1) : M[j][k];
			}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (M[i][j].first.first == INF)cout << "0 ";
			else cout << M[i][j].first.first << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (M[i][j].first.first == INF || M[i][j].first.first == 0)cout << "0\n";
			else cout << M[i][j].second << " " << M[i][j].first.second << "\n";
		}
	return 0;
}