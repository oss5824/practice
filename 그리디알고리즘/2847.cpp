#pragma warning(disable: 4996)
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF 1e9
typedef long long ll;
using namespace std;
int N, arr[100];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++)cin >> arr[i];
	for (int i = N - 1; i > 0; i--) {
		if (arr[i - 1] < arr[i])continue;
		while (arr[i - 1] >= arr[i]) {
			arr[i - 1]--; cnt++;
		}
	}
	cout << cnt;
	return 0;
}


