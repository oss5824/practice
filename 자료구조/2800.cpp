#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
string s;
vector<pair<int, int>>v;
vector<pair<int, int>>res;
int lenV;
vector<string>result;
bool visit[11];

void push_result()
{
	int len = res.size();
	if (len == 0)return;
	vector<int>order;
	for (int i = 0; i < len; i++) {
		int a = res[i].first, b = res[i].second;
		order.push_back(a); order.push_back(b);
	}
	sort(order.begin(), order.end());
	string tmp;
	len = s.length();
	for (int i = 0, idx = 0; i < len; i++) {
		if (idx < order.size() && i == order[idx]) { idx++; }
		else tmp.push_back(s[i]);
	}
	result.push_back(tmp);
}
void solve(int num)
{
	push_result();
	for (int i = num; i < lenV; i++) {
		if (!visit[i]) {
			res.push_back(v[i]);
			visit[i] = true;
			solve(i);
			res.pop_back();
			visit[i] = false;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> s;
	int len = s.length();
	stack<pair<int, char>>st;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(')st.push({ i,'(' });
		else if (s[i] == ')') {
			int start = st.top().first; st.pop();
			v.push_back({ start,i });
		}
	}
	lenV = v.size(); solve(0);
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	for (string tmp : result)cout << tmp << "\n";
	return 0;
}

