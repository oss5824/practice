#include<iostream>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int a, b, c, d; char ch[6] = { 'D','C','B','A','E' };
	while (cin >> a)
	{
		int cnt = 0;
		cin >> b >> c >> d; if (a == 1)cnt++; if (b == 1)cnt++; if (c == 1)cnt++; if (d == 1)cnt++;
		cout << ch[cnt] << "\n";
	}
	return 0;
}

