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
string s;
int N;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	cin >> s >> N;
	int cnt = 0;
	while (N--) {
		string str; cin >> str;
		int len = str.length();
		for (int k = 0; k < len; k++) {
			char c = str[0];
			for (int i = 0; i < len - 1; i++)str[i] = str[i + 1];
			str[len - 1] = c;
			if (str.find(s, 0) != string::npos) { cnt++; break; }
		}
	}
	cout << cnt;
	return 0;
}


