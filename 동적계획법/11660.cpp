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
#define INF INT_MAX
using namespace std;
int N, K, M[1025][1025];
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			int a; cin >> a;
			if (j == 1)M[i][j] = a;
			else M[i][j] = M[i][j - 1] + a;
		}
	while (K--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		int sum = 0;
		for (int i = a; i <= c; i++)sum = sum + M[i][d] - M[i][b - 1];
		cout << sum << "\n";
	}
	return 0;
}