#include<iostream>
#include<stack>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	string s; cin >> s; int len = s.length(), val = 1, sum = 0; stack<char>st;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(') { val *= 2; st.push(s[i]); }
		else if (s[i] == '[') { val *= 3; st.push(s[i]); }
		else if (s[i] == ')')
		{
			if (st.empty() || st.top() != '(') { cout << "0"; return 0; }
			if (s[i - 1] == '(')sum += val;
			st.pop(); val /= 2;
		}
		else if (s[i] == ']')
		{
			if (st.empty() || st.top() != '[') { cout << "0"; return 0; }
			if (s[i - 1] == '[')sum += val;
			st.pop(); val /= 3;
		}
	}if (!st.empty())cout << "0"; else cout << sum;
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);