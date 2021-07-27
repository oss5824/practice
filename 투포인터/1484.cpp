#define _CRT_SECURE_NO_WARNINGS 
#include<cstdio>
int main()
{
	int N, s = 1, e = 2; scanf("%d", &N);
	bool check = false;
	while (s < e) {
		int sum = e * e - s * s;
		if (sum == N) { printf("%d\n", e); s++; e++; check = true; }
		else if (sum < N)e++;
		else s++;
	}if (!check)printf("-1");
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);