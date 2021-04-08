#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int r, c, k;
int arr[101][101];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); 
	cin >> r >> c >> k;
	int second = 0, row = 3, col = 3, a;
	for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++) { cin >> arr[i][j]; }
	if (arr[r - 1][c - 1] == k) { cout << "0"; return 0; }
	while (second <= 100)
	{
		if (row >= col)
		{
			int max_col = 0;
			for (int i = 0; i < row; i++)
			{
				vector<pair<int, int>>v;
				int cnt[101] = { 0 };
				for (int j = 0; j < col; j++)  cnt[arr[i][j]]++;
				for (int j = 1; j <= 100; j++)if (cnt[j] > 0)v.push_back({ cnt[j],j });
				sort(v.begin(), v.end()); int idx = 0;
				for (auto p:v)
				{
					if (idx >= 99)break;
					arr[i][idx++] = p.second;
					arr[i][idx++] = p.first;
				}
				max_col = max(max_col, idx);
				for (int j = idx; j < 100; j++)arr[i][j] = 0;
			}
			col = max_col;
		}
		else
		{
			int max_row = 0;
			for (int i = 0; i < col; i++)
			{
				vector<pair<int, int>>v;
				int cnt[101] = { 0 };
				for (int j = 0; j < row; j++)  cnt[arr[j][i]]++;
				for (int j = 1; j <= 100; j++)if (cnt[j] > 0)v.push_back({ cnt[j],j });
				sort(v.begin(), v.end()); int idx = 0;
				for (auto p : v)
				{
					if (idx >= 99)break;
					arr[idx++][i] = p.second;
					arr[idx++][i] = p.first;
				}
				max_row = max(max_row, idx);
				for (int j = idx; j < 100; j++)arr[j][i] = 0;
			}
			row = max_row;
		}
		second++;
		if (arr[r - 1][c - 1] == k) { cout << second; return 0; }
	}cout << "-1";
	return 0;
}
