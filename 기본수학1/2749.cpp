#pragma warning(disable:4996)
#include <stdio.h>
long long N, a, b = 1, c = 1;
int main(){
	scanf("%lld", &N);
	N %= 1500000;
	while (--N) { c = (a + b) % 1000000; a = b; b = c; }
	printf("%d", c);
}