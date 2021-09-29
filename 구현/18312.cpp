#pragma warning(disable: 4996)
#include<stdio.h>
int n, k, s, e, all, h, m, res;
bool cnt(int num)
{
	if (num / 10 == k || num % 10 == k)return true;
	return false;
}
int main(){
	scanf("%d %d", &n, &k);
	e = n * 3600 + 60 * 59 + 59;
	while (s <= e) {
		all = s;
		h = all / 3600;
		all -= h * 3600;
		m = all / 60;
		all -= m * 60;
		if (cnt(h) || cnt(m) || cnt(all))res++;
		s++;
	}printf("%d", res);
}