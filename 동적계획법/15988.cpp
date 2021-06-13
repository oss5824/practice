#pragma warning(disable: 4996)
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
#define INF LLONG_MAX
#define CONST 1000000009
typedef long long ll;
using namespace std;
unsigned long long Cache[1000001], N;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	Cache[1] = 1; Cache[2] = 2; Cache[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		Cache[i] = (Cache[i - 1] % CONST + Cache[i - 2] % CONST + Cache[i - 3] % CONST) % CONST;
	}
	while (N--) {
		int a; cin >> a; cout << Cache[a] << "\n";
	}
	return 0;
}


