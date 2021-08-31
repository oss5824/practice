#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
using namespace std;
char s[11]; int r, l;
int main()
{
	scanf("%s", s); while (s[l] != NULL)l++; sort(s, s + l);
	do {
		bool c = false; for (int i = 1; i < l; i++)if (s[i - 1] == s[i]) { c = true; break; }
		if (!c)r++;
	} while (next_permutation(s, s + l));
	printf("%d", r);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
//for (int i = 0; i < len; i++)printf("%c", s[vc[i]]); printf("\n");