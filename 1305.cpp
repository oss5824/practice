#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
string P;
int n;
vector<int>pi;
void KMP()
{
	for (int i = 1, j = 0; i < n; i++)
	{
		while (j > 0 && P[i] != P[j])j = pi[j - 1];
		if (P[i] == P[j])pi[i] = ++j;
	}
	cout << n - pi[n - 1];
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n; cin.ignore(); cin >> P; pi.assign(n + 1, 0);
	KMP();
	return 0;
}