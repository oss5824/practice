#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
int N, M[1500001], a, b, res;
int main()
{
	cin.tie(NULL);  ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1, idx; i <= N; i++) {
		cin >> a >> b;
		idx = i + a - 1;
		M[i] = max(M[i], M[i - 1]);
		if (idx > N)continue;
		M[idx] = max(M[i - 1] + b, M[idx]);
		res = max(M[idx], res);
	}
	cout << res;
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);