#include <iostream>
#include <map>
using namespace std;
map<char, pair<char, char>>m;
void pre(char c)
{
	cout << c;
	if (m[c].first != '.')pre(m[c].first);
	if (m[c].second != '.')pre(m[c].second);
}
void in(char c)
{
	if (m[c].first != '.')in(m[c].first);
	cout << c;
	if (m[c].second != '.')in(m[c].second);
}
void post(char c)
{
	if (m[c].first != '.')post(m[c].first);
	if (m[c].second != '.')post(m[c].second);
	cout << c;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n; char a, b, c;
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a >> b >> c; m[a] = { b,c }; }
	pre('A'); cout << "\n"; in('A'); cout << "\n"; post('A');
	return 0;
}