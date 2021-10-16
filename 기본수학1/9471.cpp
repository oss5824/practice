#pragma warning(disable:4996)
#include <stdio.h>
int N, M, t;
int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &N, &M);
		int p = -1, a = 0, b = 1, c = 0, result = 1;
		while (1) {
			c = (a + b) % M;
			if (p == 0 && c % M == 1)break;
			p = c; a = b; b = c;
			result++;
		}printf("%d %d\n", N, result);
	}
}