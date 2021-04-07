#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
using namespace std;
short arr[26];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	string s, result; cin >> s; int len = s.length(), start = 0, cnt = 0;
	for (int i = 0; i < len; i++) arr[s[i] - 'A']++;
	for (int i = 0; i < 26; i++)if (arr[i] % 2 != 0)cnt++;
	if (cnt > 1) { cout << "I'm Sorry Hansoo"; return 0; }
	queue<char>q; stack<char>st;
	char c;
	while (start <= 25){
		while (arr[start] != 0) {
			if (arr[start] != 1) {
				q.push(start + 'A'); st.push(start + 'A');
				arr[start] -= 2;
			}
			else { c = (char)(start + 'A'); arr[start]--; }
		}
		start++;
	}
	while (!q.empty()) { result += q.front(); q.pop(); }
	if (cnt != 0)result += c;
	while (!st.empty()) { result += st.top(); st.pop(); }
	cout << result;
	return 0;
}

