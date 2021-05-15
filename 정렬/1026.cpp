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
int arr1[50], arr2[50];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)cin >> arr1[i];
	for (int i = 0; i < N; i++)cin >> arr2[i];
	sort(arr1, arr1 + N); sort(arr2, arr2 + N, greater<int>());
	int sum = 0;
	for (int i = 0; i < N; i++)sum += arr1[i] * arr2[i];
	cout << sum;
	return 0;
}