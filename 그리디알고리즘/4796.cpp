#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M, cnt = 1;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	while (1)
	{
		int a, b, c, res = 0; cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)break;
		res = a * (c / b) + min((c % b), a);
		cout << "Case " << cnt << ": " << res << "\n";
		cnt++;
	}
	return 0;
}