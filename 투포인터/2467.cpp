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
int N, arr[100000], sum = INF;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)cin >> arr[i];
	int s = 0, e = N - 1, res_s = 0, res_e = 0;
	while (s < e)
	{
		int val = abs(arr[s] + arr[e]);
		if (val < sum) { sum = val; res_s = s; res_e = e; }
		if (abs(arr[s + 1] + arr[e]) < abs(arr[s] + arr[e - 1]))s++;
		else e--;
	}
	cout << arr[res_s] << " " << arr[res_e];
	return 0;
}