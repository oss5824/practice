#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#include<limits.h>
#define INF 1e9
using namespace std;
int N;
int arr[1001], M[1001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> arr[i];
	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N; j++)
			M[j] = max(M[j], M[j - i] + arr[i]);
	cout << M[N];
	return 0;
}