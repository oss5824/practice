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
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	string s; cin >> s;
	int len = s.length();
	stack<char>st; 
	int cnt = 0, result = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(')
		{
			if (s[i + 1] == ')') { result += cnt; i++; }
			else { st.push('('); cnt++; }
		}
		else
		{
			cnt--; result++;
			st.pop();
		}
	}
	cout << result;
	return 0;
}