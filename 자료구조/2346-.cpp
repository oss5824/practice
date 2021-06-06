#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF INT_MAX
typedef unsigned long long ull;
using namespace std;
int N, arr[1001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; for (int i = 1; i <= N; i++)cin >> arr[i];
	int idx = 1;
	for (int k = 0; k < N; k++) {
		int len = arr[idx];
		arr[idx] = 0;
		cout << idx << " ";
		if (k == N - 1)break;
		if (len > 0) {
			while (len--) {
				idx++; if (idx == N + 1)idx = 0;
				if (arr[idx] == 0)len++;
			}
		}
		else {
			len = len * -1;
			while (len--) {
				idx--; if (idx == 0)idx = N;
				if (arr[idx] == 0)len++;
			}
		}
	}
	return 0;
}
