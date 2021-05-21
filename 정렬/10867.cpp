#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<limits.h>
#define INF 1e9
using namespace std;
int N;
vector<int>v;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; for (int i = 0; i < N; i++) { int a; cin >> a; v.push_back(a); }
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i : v)cout << i << " ";
	return 0;
}