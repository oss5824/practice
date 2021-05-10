#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<limits.h>
#define INF INT_MAX
using namespace std;
bool group[10][9];
bool width[10][9];
bool height[10][9];
char Map[9][10];
bool fin = false;
vector<pair<int, int>>v;
int Group(int x, int y) {
	int g = 0;
	if (y < 3 && x < 3)g = 0; else if (y < 3 && x < 6)g = 1; else if (y < 3 && x < 9)g = 2;
	else if (y < 6 && x < 3)g = 3; else if (y < 6 && x < 6)g = 4; else if (y < 6 && x < 9)g = 5;
	else if (y < 9 && x < 3)g = 6; else if (y < 9 && x < 6)g = 7; else if (y < 9 && x < 9)g = 8;
	return g;
}
void solve(int num)
{
	if (fin)return;
	if (num == v.size()){
		for (int i = 0; i < 9; i++)cout << Map[i] << "\n";
		fin = true;
		return;
	}
	int x = v[num].first, y = v[num].second;
	int group_num = Group(x, y);
	for (int i = 1; i <= 9; i++){
		if (fin)return;
		if (!group[i][group_num] && !width[i][y] && !height[i][x]) {
			Map[y][x] = i + '0';
			group[i][group_num] = true; width[i][y] = true; height[i][x] = true;
			solve(num + 1);
			if (fin)return;
			group[i][group_num] = false; width[i][y] = false; height[i][x] = false;
		}
	}
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);

	for (int i = 0; i < 9; i++)cin >> Map[i];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++){
			if (Map[i][j] != '0') {
				group[Map[i][j] - '0'][Group(j, i)] = true;
				width[Map[i][j] - '0'][i] = true;
				height[Map[i][j] - '0'][j] = true;
			}
			else v.push_back({ j,i });
		}
	solve(0);
	return 0;
}