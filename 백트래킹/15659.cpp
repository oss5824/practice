#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int N, r1 = -2e9, r2 = 2e9;
vector<int>v;
string n = "", p = "+-*/", s;
int cal(int a,int b, char c)
{
	if (c == '+')return a + b;
	else if (c == '-')return a - b;
	else if (c == '*')return a * b;
	else return a / b;
}
void fun1(int idx2)
{
	int sum = cal(v[idx2], v[idx2 + 1], s[idx2]);
	v.erase(v.begin() + idx2); v[idx2] = sum;
	s.erase(idx2, 1);
}
void fun2(int idx1)
{
	int sum = cal(v[idx1], v[idx1 + 1], s[idx1]);
	v.erase(v.begin() + idx1); v[idx1] = sum;
	s.erase(idx1, 1);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0, a; i < N; i++) { cin >> a; v.push_back(a); }
	for (int i = 0, a; i < 4; i++) { cin >> a; while (a != 0) { n.push_back(p[i]); a--; } }
	sort(n.begin(), n.end());
	do {
		s = n;
		vector<int>tmp = v;
		while (1) {
			int idx1 = s.find('*', 0), idx2 = s.find('/', 0);
			if (idx1 == -1 && idx2 == -1)break;
			if (idx1 == string::npos) fun1(idx2);
			else if (idx2 == string::npos)fun2(idx1);
			else if (idx2 < idx1) fun1(idx2);
			else if (idx1 < idx2) fun2(idx1);
			if (s.empty())break;
		}
		int sum = v[0], len = v.size();
		for (int i = 0; i < len - 1; i++)sum = cal(sum, v[i + 1], s[i]);
		r1 = max(r1, sum); r2 = min(r2, sum);v = tmp;
	} while (next_permutation(n.begin(), n.end()));
	cout << r1 << "\n" << r2;
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);


