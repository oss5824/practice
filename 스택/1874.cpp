#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
	cin.tie(NULL);ios::sync_with_stdio(false);
	int n, val;
	cin >> n;
	stack <int>s;
	vector<char>res;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		cin >> val;
		while (cnt <= val) { s.push(cnt++); res.push_back('+'); }
		if (s.top() == val) { s.pop(); res.push_back('-'); }
		else { cout << "NO"; return 0; }
	}
	for (char i : res)cout << i << "\n";	
}