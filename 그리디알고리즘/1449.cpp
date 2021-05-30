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
typedef unsigned long long ull;
int N, M;
int arr[1000];
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> arr[i];
	sort(arr, arr + N);
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int len = M - 1;
		int start = arr[i];
		while (start + len >= arr[i + 1])i++;
		cnt++;
	}
	cout << cnt;
	return 0;
}