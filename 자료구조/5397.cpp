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
#define INF 1e9
typedef long long ll;
using namespace std;
int T;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		string s; cin >> s;
		list<char>l;
		auto pos = l.begin();
		for (char c : s){
			if (c == '-') {
				if (pos == l.begin())continue;
				pos = l.erase(--pos);
			}
			else if (c == '<') {
				if (pos == l.begin())continue;
				pos--;
			}
			else if (c == '>') {
				if (pos == l.end())continue;
				pos++;
			}
			else {
				l.insert(pos, c);
			}
		}
		for (char c : l)cout << c;
		cout << "\n";
	}
	return 0;
}


