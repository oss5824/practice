#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
using namespace std;
int N, result = INT_MAX;
int arr[3][3], Map[3][3];
vector<int>v;
bool visit[10]; 
bool check()
{
	if (arr[0][0] + arr[0][1] + arr[0][2] != 15)return false;
	if (arr[1][0] + arr[1][1] + arr[1][2] != 15)return false;
	if (arr[2][0] + arr[2][1] + arr[2][2] != 15)return false;
	if (arr[0][0] + arr[1][0] + arr[2][0] != 15)return false;
	if (arr[0][1] + arr[1][1] + arr[2][1] != 15)return false;
	if (arr[0][2] + arr[1][2] + arr[2][2] != 15)return false;
	if (arr[0][0] + arr[1][1] + arr[2][2] != 15)return false;
	if (arr[2][0] + arr[1][1] + arr[0][2] != 15)return false;
	return true;
}
void solve(int num)
{
	if (v.size() == 9)
	{
		int cnt = 0;
		for (int i : v) { arr[cnt / 3][cnt % 3] = i; cnt++; }
		if (check())
		{
			int sum = 0;
			for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)sum += abs(Map[i][j] - arr[i][j]);
			result = min(sum, result);
		}
		return;
	}
	for (int i = num; i <= 9; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			v.push_back(i);
			solve(num);
			v.pop_back();
			visit[i] = false;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)cin >> Map[i][j];
	solve(1);
	cout << result;
	return 0;
}