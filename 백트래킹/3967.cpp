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
#define INF 1e9
typedef long long ll;
using namespace std;
char Map[5][10];
bool visit[13];
int charToNum(char c) { return (c - 'A') + 1; }
bool check()
{
	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0;
	sum1 = charToNum(Map[0][4]) + charToNum(Map[1][3]) + charToNum(Map[2][2]) + charToNum(Map[3][1]);
	if (sum1 != 26)return false;
	sum2 = charToNum(Map[0][4]) + charToNum(Map[1][5]) + charToNum(Map[2][6]) + charToNum(Map[3][7]);
	if (sum2 != 26)return false;
	sum3 = charToNum(Map[3][1]) + charToNum(Map[3][3]) + charToNum(Map[3][5]) + charToNum(Map[3][7]);
	if (sum3 != 26)return false;
	sum4 = charToNum(Map[1][1]) + charToNum(Map[2][2]) + charToNum(Map[3][3]) + charToNum(Map[4][4]);
	if (sum4 != 26)return false;
	sum5 = charToNum(Map[4][4]) + charToNum(Map[3][5]) + charToNum(Map[2][6]) + charToNum(Map[1][7]);
	if (sum5 != 26)return false;
	sum6 = charToNum(Map[1][1]) + charToNum(Map[1][3]) + charToNum(Map[1][5]) + charToNum(Map[1][7]);
	if (sum6 != 26)return false;
	return true;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	for (int i = 0; i < 5; i++)cin >> Map[i];
	vector<int>v;
	string s;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++){
			if (isalpha(Map[i][j])) {
				if (Map[i][j] == 'x')v.push_back({ i * 9 + j }); else visit[Map[i][j] - 'A'] = true;
			}
		}
	for (int i = 0; i < 12; i++)if (!visit[i])s.push_back(i + 'A');
	int len = s.size();
	do {
		for (int i = 0; i < len; i++) Map[v[i] / 9][v[i] % 9] = s[i];
		if (check()) {
			for (int i = 0; i < 5; i++) { for (int j = 0; j < 9; j++)cout << Map[i][j]; cout << "\n"; }
			break;
		}
	} while (next_permutation(s.begin(), s.end()));
	return 0;
}


