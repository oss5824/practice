#include<iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define INF 1000000000
using namespace std;
int N;
int arr[12];
bool visit[12];
vector<int>v;
void solve(int num)
{
	if (v.size() == 6)
	{
		for (int i : v)cout << i << " ";
		cout << "\n";
		return;
	}
	for (int i = num; i < N; i++)
		if (!visit[i]) {
			visit[i] = true; v.push_back(arr[i]); solve(i); v.pop_back(); visit[i] = false;
		}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	while (1) {
		cin >> N; if (N == 0)break; 
		memset(arr, 0, sizeof(arr)); memset(visit, false, sizeof(false)); v.clear();
		for (int i = 0; i < N; i++)cin >> arr[i];
		solve(0);
		cout << "\n";
	}
	
	return 0;
}