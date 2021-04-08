#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
string P;
int len_P;
vector<int>pi;
void KMP()
{
	for (int i = 1, j = 0; i < len_P; i++)
	{
		while (j > 0 && P[i] != P[j])j = pi[j - 1];
		if (P[i] == P[j])pi[i] = ++j;
	}
	if ((len_P) % (len_P - pi[len_P - 1]) != 0)cout << "1\n";
	else cout << (len_P) / (len_P - pi[len_P - 1]) << "\n";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	while (1)
	{
		P.clear(); cin >> P;
		if (P == ".")break;
		len_P = P.length(); pi.assign(len_P, 0);
		KMP();
	}
	return 0;
}