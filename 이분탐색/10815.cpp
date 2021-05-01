#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M, arr[500000];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; for (int i = 0; i < N; i++)cin >> arr[i];
	sort(arr, arr + N);
	cin >> M;
	while (M--) {
		int a; cin >> a;
		int s = 0, e = N - 1;
		bool check = false;
		while (s <= e) {
			int m = (s + e) / 2;
			if (arr[m] == a) { check = true; break; }
			else if (arr[m] < a)s = m + 1;
			else e = m - 1;
		}
		cout << check << " ";
	}
	return 0;
}

