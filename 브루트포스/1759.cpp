#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, M;
vector<char>v;
char arr[16];
bool visit[16];
void dfs(int num)
{
	if (v.size() == N)
	{
		int one = 0, two = 0;
		for (char c : v){
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')one++;
			else two++;
		}
		if (one >= 1 && two >= 2){
			for (char c : v)cout << c;
			cout << "\n";
		}
		return;
	}
	for (int i = num; i < M; i++)
	{
		if (!visit[i])
		{
			v.push_back(arr[i]);
			visit[i] = true;
			dfs(i + 1);
			v.pop_back();
			visit[i] = false;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++)cin >> arr[i];
	sort(arr, arr + M);
	dfs(0);
	return 0;
}

