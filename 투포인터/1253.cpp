#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int N, a[2000], cnt = 0; scanf("%d", &N); for (int i = 0; i < N; i++)scanf("%d", a + i); sort(a, a + N);
	for (int i = 0; i < N; i++) {
		int s = 0, e = N - 1, m = a[i];
		while (s < e) {
			int sum = a[s] + a[e];
			if (s == i) { s++; continue; }
			else if (e == i) { e--; continue; }
			if (m > sum)s++; else if (m < sum) e--; else { cnt++; break; }
		}
	}printf("%d", cnt);
}
