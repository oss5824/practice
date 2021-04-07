#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
using namespace std;
short arr[102];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int N, T; cin >> N;
	for (int i = 1; i <= N; i++)cin >> arr[i]; arr[0] = -1; arr[N + 1] = -1;
	cin >> T;
	while (T--) {
		int a, b; cin >> a >> b;
		if (a == 1)for (int i = b; i <= N; i += b)if (arr[i] == 0)arr[i] = 1; else arr[i] = 0;
		else {
			int left = b - 1, right = b + 1; if (arr[b] == 0)arr[b] = 1; else arr[b] = 0;
			while (arr[left] == arr[right]){
				if (arr[left] == 0)arr[left] = 1; else arr[left] = 0;
				if (arr[right] == 0)arr[right] = 1; else arr[right] = 0;
				left--; right++;
			};
		}
	}
	for (int i = 1; i <= N; i++) { cout << arr[i] << " "; if (i % 20 == 0)cout << "\n"; }
	return 0;
}

