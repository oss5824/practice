#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int N;
bool v[7500001];
vector<int>res;
int main()
{
	scanf("%d", &N);
	for (int i = 2; i * i <= 7500001; i++) {
		if (v[i])continue;
		for (int j = i + i; j <= 7500001; j += i)v[j] = true;
	}
	for (int i = 2; i <= 7500001; i++)if (!v[i])res.push_back(i);
	printf("%d", res[N - 1]);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
