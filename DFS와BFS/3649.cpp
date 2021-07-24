#include<iostream>
#include<algorithm>
using namespace std;
int x, N, a[1000000];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	while (cin>>x) {
		x *= 10000000;
		cin >> N; for (int i = 0; i < N; i++)cin >> a[i]; sort(a, a + N);
		int s = 0, e = N - 1; bool c = false;
		while (s < e) {
			int S = a[s] + a[e];
			if (S == x) { cout << "yes " << a[s] << " " << a[e] << "\n"; c = true; break; }
			else if (S > x)e--;
			else s++;
		}
		if (!c)cout << "danger\n";
	}
	return 0;
}