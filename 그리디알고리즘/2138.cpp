#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int N, cnt, res;
char a[100001], b[100001], c[100001];
bool f;
char ch(char s) { return s == '0' ? '1' : '0'; }
bool check(int i) { return b[i] == a[i]; }
int main()
{
	scanf("%d %s %s", &N, a, b);
	for (int i = 0; i < N; i++)c[i] = b[i];
	for (int i = 1; i < N - 1; i++) {
		if (a[i - 1] != b[i - 1]) { b[i - 1] = ch(b[i - 1]); b[i] = ch(b[i]); b[i + 1] = ch(b[i + 1]); res++; }
		if (!check(i - 1)) { f = true; break; }
	}
	if (!check(N - 2))cnt++; if (!check(N - 1))cnt++;
	if (!f && cnt != 1)printf("%d", res + cnt / 2);
	else {
		cnt = 0; res = 1; f = false; for (int i = 0; i < N; i++)b[i] = c[i];
		b[0] = ch(b[0]), b[1] = ch(b[1]);
		for (int i = 1; i < N - 1; i++) {
			if (a[i - 1] != b[i - 1]) { b[i - 1] = ch(b[i - 1]); b[i] = ch(b[i]); b[i + 1] = ch(b[i + 1]); res++; }
			if (!check(i - 1)) { f = true; break; }
		}if (!check(N - 2))cnt++; if (!check(N - 1))cnt++;
		if (f || cnt == 1)printf("-1");
		else printf("%d", res + cnt / 2);
	}
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
