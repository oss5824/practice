#include<stdio.h>
long long v[100000], n, k, pos, idx;
int main(){
	scanf("%lld %lld", &n, &k);
	bool check = false;
	for (int i = 0; i < n; i++)scanf("%lld", v + i);
	while (pos + v[idx] <= k) {
		pos += v[idx];
		if (!check) {if (idx == n - 1)check = true;else idx++;}
		else {idx--;if (idx < 0)break;}
	}printf("%lld", idx + 1);
}
/*
5 43
7 4 2 4 5
*/