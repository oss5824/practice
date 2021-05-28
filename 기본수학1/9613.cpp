#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<limits.h>
#define INF 1e9
typedef long long ll;
using namespace std;
int T, N, arr[100];
ll gcd(int a, int b)
{
	if (a < b)swap(a, b);
	while (b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N; memset(arr, 0, sizeof(arr));
		for (int i = 0; i < N; i++)cin >> arr[i];
		long long sum = 0;
		for (int i = 0; i < N - 1; i++)for (int j = i + 1; j < N; j++)sum += gcd(arr[i], arr[j]);
		cout << sum << "\n";
	}

	return 0;
}