#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
using namespace std;

int N, arr[50];

bool check() { for (int i = 0; i < N; i++)if (arr[i] != 0)return false; return true; }
bool divCheck() { for (int i = 0; i < N; i++)if (arr[i] % 2 != 0)return false; return true; }
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; for (int i = 0; i < N; i++)cin >> arr[i];
	int cnt = 0;
	while (1)
	{
		if (check()) { break; }
		cnt++;
		if (divCheck()) for (int i = 0; i < N; i++)arr[i] = arr[i] / 2;
		else for (int i = 0; i < N; i++)if (arr[i] % 2 != 0) { arr[i]--; break; }
	}
	cout << cnt;
	return 0;
}