#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
int n, a, sz;
bool Mrow[10][10];
bool Mcol[10][10];
bool Map[10][10];
int arr[10][10];
vector<pair<int, int>>v;
vector<int>res;
bool finish = false;
int Group(int j, int i)
{
	int group = 0;
	if (i <= 3 && j <= 3)group = 1; else if (i <= 3 && j <= 6)group = 2; else if (i <= 3 && j <= 9)group = 3;
	else if (i <= 6 && j <= 3)group = 4; else if (i <= 6 && j <= 6)group = 5; else if (i <= 6 && j <= 9)group = 6;
	else if (i <= 9 && j <= 3)group = 7; else if (i <= 9 && j <= 6)group = 8; else if (i <= 9 && j <= 9)group = 9;
	return group;
}
bool check(int x, int y, int val)
{
	int group = Group(x, y);
	if (Mrow[y][val])return false;
	if (Mcol[x][val])  return false;
	if (Map[group][val]) return false;
	return true;
}
void stok(int idx)
{
	if (idx == sz)
	{
		int index = 0;
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (arr[i][j] != 0)cout << arr[i][j] << " ";
				else cout << res[index++] << " ";
			}
			cout << "\n";
		}
		finish = true;
	}
	if (finish)return;
	int x = v[idx].first, y = v[idx].second;
	bool backMrow[10][10], backMcol[10][10], backMap[10][10];
	vector<int>backV(idx, 0);
	for (int i = 1; i <= 9; i++)
	{
		memcpy(backMrow, Mrow, sizeof(Mrow)); memcpy(backMcol, Mcol, sizeof(Mrow)); memcpy(backMap, Map, sizeof(Mrow));
		backV = res;
		if (check(x, y, i))
		{
			Mrow[y][i] = true; Mcol[x][i] = true; Map[Group(x, y)][i] = true; res.push_back(i); stok(idx + 1);
		}
		if (finish)break;
		res = backV;
		memcpy(Mrow, backMrow, sizeof(Mrow)); memcpy(Mcol, backMcol, sizeof(Mrow)); memcpy(Map, backMap, sizeof(Mrow));
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); 
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
		{
			int group = Group(j, i);
			cin >> a; arr[i][j] = a;
			if (a == 0)v.push_back({ j, i });
			else {
				Mrow[i][a] = true;
				Mcol[j][a] = true;
				Map[group][a] = true;
			}
		}
	sz = v.size();
	stok(0);
	return 0;
}
