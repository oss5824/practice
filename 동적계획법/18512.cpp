#pragma warning(disable: 4996)
#include<stdio.h>
int d1, d2, p1, p2, res = 1e9;
int main(){
	scanf("%d %d %d %d", &d1, &d2, &p1, &p2);
	for (int i = p1; i <= 10000; i += d1) {
		for (int j = p2; j <= 10000; j += d2) if (i == j && res > i)res = i;	
	}
	if (res == 1e9)res = -1; printf("%d", res);
}