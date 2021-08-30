#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, x[100000], y[100000], r;
int main()
{
	cin.tie(NULL);ios::sync_with_stdio(false);
	cin >> n >> m; for (int i = 0; i < m; i++)cin >> x[i] >> y[i];
	sort(x, x + m); sort(y, y + m); 
	for (int i = 0; i < m; i++) {
		int a = x[i] - x[m / 2], b = y[i] - y[m / 2];
		if (a < 0)a *= -1; if (b < 0)b *= -1;
		r = r + a + b;
	}
	printf("%d", r);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
