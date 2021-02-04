#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
char T[1000001], P[1000001], token[100001];
int len_T, len_P;
vector<int>pi;
void KMP()
{
	for (int i = 1, j = 0; i < len_P; i++)
	{
		while (j > 0 && P[i] != P[j])j = pi[j - 1];
		if (P[i] == P[j])pi[i] = ++j;
	}
	vector<int>result;
	for (int i = 0, j = 0; i < len_T; i++)
	{
		while (j > 0 && T[i] != P[j])j = pi[j - 1];
		if (T[i] == P[j])
		{
			if (j == len_P - 1) { result.push_back(i - j + 1); j = pi[j]; }
			else j++;
		}
	}
	cout << result.size() << "\n"; for (auto i : result)cout << i << " ";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin.getline(T, sizeof(T)); cin.getline(P, sizeof(P));
	len_T = strlen(T); len_P = strlen(P); pi.assign(len_P, 0);
	KMP();
	return 0;
}