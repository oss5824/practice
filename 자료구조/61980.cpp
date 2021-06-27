#include <iostream>
#include <stack>
using namespace std;
int N, arr[80000];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; for (int i = 0; i < N; i++)cin >> arr[i];
	stack<int>st; st.push(arr[0]);
	long long answer = 0;
	for (int i = 1; i < N; i++) {
		int a = st.top(), b = arr[i];
		while (a <= b) { st.pop(); if (st.empty())break; a = st.top(); }
		answer += (long long)st.size(); st.push(b);
	}
	cout << answer;
}
/*
#include <iostream>
#include <stack>
using namespace std;
int N, arr[80000];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; for (int i = 0; i < N; i++)cin >> arr[i];
	stack<int>st; st.push(arr[N - 1]);
	long long answer = 0;
	for (int i = N-2; i >= 0; i--) {
		int a = st.top(), b = arr[i];
		while (b <= a) { st.pop(); if (st.empty())break; }
		answer += (long long)st.size();
		cout << answer << " ";
		st.push(b);
	}
	cout << answer;
}
*/