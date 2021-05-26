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
int N;
vector<int>v;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; for (int i = 0; i < N; i++) { int a; cin >> a; v.push_back(a); }
	stack<pair<int, int>>st;
	st.push({ v[0] ,1 });
	int count = 0;
	cout << "0 ";
	for (int i = 1; i < N; i++){
		int a = st.top().first, b = v[i];
		while (a <= b) { st.pop(); if (st.empty())break; a = st.top().first; }
		if (st.empty())cout << "0 ";
		else cout << st.top().second << " ";
		st.push({ b,i + 1 });
	}
	return 0;
}