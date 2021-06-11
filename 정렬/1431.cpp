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
int N;
vector<string>v;
bool cmp(string a, string b) 
{
	int len1 = a.length(), len2 = b.length();
	if (len1 < len2)return true;
	else if (len1 > len2)return false;
	else {
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < len1; i++)if (isdigit(a[i]))sum1 += a[i] - '0';
		for (int i = 0; i < len2; i++)if (isdigit(b[i]))sum2 += b[i] - '0';
		if (sum1 < sum2)return true;
		else if (sum1 > sum2)return false;
		else return a < b;
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++){
		string s; cin >> s; v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	for (string s : v)cout << s << "\n";
	return 0;
}


