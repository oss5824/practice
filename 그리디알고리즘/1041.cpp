#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	long long arr[6], N, M = 0, sum = 0, cub1 = 1e9, cub2 = 1e9, cub3 = 1e9; scanf("%lld", &N);
	for (int i = 0; i < 6; i++) {
		scanf("%lld", arr + i); if (arr[i] < cub1)cub1 = arr[i]; if (arr[i] > M)M = arr[i]; sum += arr[i];
	}
	if (N == 1) { printf("%lld", sum - M); return 0; }
	for (int i = 0; i < 6; i++)
		for (int j = i + 1; j < 6; j++) {
			if ((i == 0 && j == 5) || (i == 1 && j == 4) || (i == 2 && j == 3))continue;
			if (arr[i] + arr[j] < cub2)cub2 = arr[i] + arr[j];
		}
	long long a = arr[1] + arr[2], b = arr[1] + arr[3], c = arr[2] + arr[4], d = arr[3] + arr[4];
	if (a < cub3)cub3 = a; if (b < cub3)cub3 = b; if (c < cub3)cub3 = c; if (d < cub3)cub3 = d;
	if (arr[0] < arr[5])cub3 += arr[0]; else cub3 += arr[5];
	long long val = 0, cnt = (N - 1) * 4 + (N - 2) * 4;
	val += cub2 * cnt; val += cub3 * 4; val += (5 * N * N - cnt * 2 - 12) * cub1;
	printf("%lld", val);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);