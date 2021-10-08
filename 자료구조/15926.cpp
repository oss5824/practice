#pragma warning(disable: 4996)
#include<stdio.h>
#include<stack>
#include<algorithm>
using namespace std;
int N, cnt, res;
stack<int>st;
char s[200001];
bool chk[200001];
int main()
{
	scanf("%d %s", &N, s);
	for (int i = 0; i < N; i++) {
		if (s[i] == '(') st.push(i);
		else if (!st.empty()) { chk[i] = 1; chk[st.top()] = 1; st.pop(); }		
	}for (bool c : chk) { if (c)cnt++, res = max(res, cnt); else cnt = 0; }
	printf("%d", res);
}