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
#define INF INT_MAX
using namespace std;
int N;
int arr[1000000];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	stack<int>st, res;
	for (int i = 0; i < N; i++)cin >> arr[i];
	st.push(arr[N - 1]);
	for (int i = N - 2; i >= 0; i--)
	{
		int a = st.top(), b = arr[i];
		while (a <= b) { st.pop(); if (st.empty())break; a = st.top(); }
		if (st.empty())res.push(-1);
		else res.push(st.top());
		st.push(b);
	}
	while (!res.empty()) { cout << res.top() << " "; res.pop(); }cout << "-1";
	return 0;
}