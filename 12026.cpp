#include <iostream>
#include <algorithm>
using namespace std;
int n, M[1001], arr[1001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); fill(M, M + 1001, 1000000000);
	cin >> n; string s; cin >> s; char c; M[0] = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'B')c = 'O';else if (s[i] == 'O')c = 'J';else if (s[i] == 'J')c = 'B';
		for (int j = i + 1; j < n; j++)
			if (s[j] == c)M[j] = min(M[j], M[i] + (j - i) * (j - i));
	}
	(M[n - 1] == 1000000000) ? cout << "-1" : cout << M[n - 1];
	return 0;
}

