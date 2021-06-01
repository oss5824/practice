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
typedef unsigned long long ull;
int T, N;
string s = "+ -";
string v;
vector<string>string_vector;
void solve(int num)
{
	if (v.size() == N - 1)
	{
		string result, tmp;
		int res = 0;
		for (int i = 1; i <= N; i++)
		{
			result += (i + '0');
			tmp += (i + '0');
			if (i == N)break;
			if (v[i - 1] != ' ')result += v[i - 1];
			tmp += v[i - 1];
		}
		int len = result.size(), idx = 0;
		char c = '*';
		while (idx<len) {
			string num;
			while (idx < len && result[idx] != '+' && result[idx] != '-'){
				num += result[idx++];
			}
			if (c == '*' || c == '+')res += stoi(num);
			else if (c == '-')res -= stoi(num);
			c = result[idx]; idx++;
		}
		if (res == 0) { string_vector.push_back(tmp); }
		return;
	}
	for (int i = num; i < 3; i++)
	{
		v.push_back(s[i]);
		solve(num);
		v.pop_back();
	}
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N;
		v.clear(); string_vector.clear();
		solve(0);
		sort(string_vector.begin(), string_vector.end());
		for (string str : string_vector)cout << str << "\n";
		cout << "\n";
	}
	return 0;
}

