#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, M;
bool breakdown[10];
bool check_breakdown(string s)
{
	if (s[0] == '-')return true;
	int len = s.length();
	for (int i = 0; i < len; i++)if (breakdown[s[i] - '0']) { return true; }
	return false;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++) { int a; cin >> a; breakdown[a] = true; }
	int root = N;
	int val1 = root, val2 = root;
	bool check1 = true, check2 = true;
	int result = abs(N - 100);
	if (M == 10) { cout << result << "\n"; return 0; }
	while (1)
	{
		if (val1 >= 0)check1 = check_breakdown(to_string(val1));
		check2 = check_breakdown(to_string(val2));
		if (!check1 || !check2)break;
		val1--; val2++;
	}
	if (!check1){
		int res = abs(N - val1) + to_string(val1).length();
		result = min(res, result);
	}
	else {
		int res = abs(N - val2) + to_string(val2).length();
		result = min(res, result);
	}
	cout << result;
	return 0;
}


