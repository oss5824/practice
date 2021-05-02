#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<limits.h>
#define INF INT_MAX
using namespace std;
typedef unsigned long long ull;
ull res = 1;
string s;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> s;
	char bef = 'x';
	for (char c : s) {
		if (c == 'c') {
			if (bef == 'c')res *= (ull)25;
			else res *= (ull)26;
			bef = 'c';
		}
		else {
			if (bef == 'd')res *= (ull)9;
			else res *= (ull)10;
			bef = 'd';
		}
	}cout << res;
	return 0;
}

