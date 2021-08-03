#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
using namespace std;
char s1[4001], s2[4001];
int dp[4001][4001];
int main()
{
	scanf("%s %s", s1, s2);
	int len1 = strlen(s1), len2 = strlen(s2), res = 0;
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				if (res < dp[i + 1][j + 1])res = dp[i + 1][j + 1];
			}
		}
	}printf("%d", res);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);