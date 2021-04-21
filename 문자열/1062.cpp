#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, K, result;
string s[50];
bool alphabet[26];
int read_string()
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int len = s[i].length(); bool check = true;
		for (int j = 0; j < len; j++)if (!alphabet[s[i][j] - 'a']) { check = false; break; }
		if (check)cnt++;
	}
	return cnt;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N;i++) {
		string sub; cin >> sub; int len = sub.length(); sub = sub.substr(4, len - 8); s[i] = sub;
	}
	alphabet[0] = true; alphabet['c' - 'a'] = true; alphabet['t' - 'a'] = true;
	alphabet['n' - 'a'] = true; alphabet['i' - 'a'] = true;
	if (K < 5)cout << "0";
	else if (K == 26)cout << N;
	else if (K == 5)cout << read_string();
	else
	{
		int n = K - 5;
		for (int i = 1; i < (1 << 26); i++)
		{
			int cnt = 0, pos = 0;
			int val = i;
			bool backUpAlphabet[26];
			bool exist = false;
			memcpy(backUpAlphabet, alphabet, sizeof(alphabet));
			while (val) {
				if (val & 1) {
					alphabet[pos] = true; cnt++;
					if (pos == 0 || pos == 2 || pos == 8 || pos == 13 || pos == 19 || cnt > n) { exist = true; break; }
				}
				val = val >> 1; pos++;
			}
			if (exist) { memcpy(alphabet, backUpAlphabet, sizeof(alphabet)); continue; }
			if (cnt == n) { result = max(result, read_string()); }
			memcpy(alphabet, backUpAlphabet, sizeof(alphabet));
		}
		cout << result;
	}
	return 0;
}


