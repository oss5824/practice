#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
int a, b, r;
bool arr[2001][2001];
int main()
{
	scanf("%d %d", &a, &b);
	for (int i = a; i <= b; i++) 
		for (int j = 0; j < i; j++) {
			int a = i, b = j, c;
			while (b) { c = a % b; a = b; b = c; }
			if (!arr[i / a][j / a]) { arr[i / a][j / a] = 1; r++; }
		}
	printf("%d", r);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);


