#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int v[10000], T, N, s;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N; for (int i = 0; i < N; i++)cin >> v[i];
		sort(v, v + N); vector<int>vec;
		for (int i = 0; i < N; i += 2)vec.push_back(v[i]);
		if (N % 2 == 0)s = N - 1; else s = N - 2;
		for (int i = s; i >= 0; i -= 2)vec.push_back(v[i]);
		vec.push_back(v[0]); int res = 0;
		for (int i = 0; i < N; i++)res = max(res, abs(vec[i] - vec[i + 1]));
		cout << res << "\n";
	}
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
