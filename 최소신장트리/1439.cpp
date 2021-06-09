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
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> s;
	int len = s.length(), idx = 0, cnt_zero = 0, cnt_one = 0;
	while (idx < len){
		if (s[idx] == '1') { idx++; continue; }
		while (s[idx] == '0')idx++;
		cnt_one++;
	}
	idx = 0;
	while (idx < len) {
		if (s[idx] == '0') { idx++; continue; }
		while (s[idx] == '1')idx++;
		cnt_zero++;
	}
	cout << min(cnt_zero, cnt_one);
	return 0;
}


