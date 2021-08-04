#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N, arr[200];
	scanf("%d", &N); for (int i = 0; i < N; i++)scanf("%d", arr + i);
	vector<int>v; v.push_back(arr[0]);
	for (int i = 1; i < N; i++) {
		if (v.back() < arr[i])v.push_back(arr[i]);
		else v[lower_bound(v.begin(), v.end(), arr[i]) - v.begin()] = arr[i];
	}
	printf("%d", N - v.size());
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);