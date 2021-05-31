#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<list>
#include<limits.h>
#define INF INT_MAX
using namespace std;
typedef unsigned long long ull;
int N, M;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	string s; int n; char c;
	cin >> s >> n;
	list<char>l(s.begin(), s.end());
	auto pos = l.end();
	while (n--) {
		cin >> c;
		if (c == 'P') { cin >> c; l.insert(pos, c);  }
		else if (c == 'L') { if (pos != l.begin())pos--; }
		else if (c == 'D') { if (pos != l.end())pos++; }
		else if (c == 'B') {
			if (pos == l.begin())continue;
			pos = l.erase(--pos);
		}
	}for (auto& a : l)cout << a;
	return 0;
}