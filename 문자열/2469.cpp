#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
char Map[1001][27];
char order[27];
char result[27];
char ladder[27];
char nope[27];
char str[27];
int N, M, idx = 0;

void check(int n)
{
	int pos = n;
	for (int i = 0; i < idx; i++)
	{
		if (pos == 0 && Map[i][pos] == '-')pos++;
		else if (pos == M - 1 && Map[i][pos - 1] == '-')pos--;
		else {
			if (Map[i][pos - 1] == '-')pos--;
			else if (Map[i][pos] == '-')pos++;
		}
	}
	str[pos] = n + 'A';
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> M >> N;
	cin >> order;
	for (int i = 0; i < M - 1; i++) nope[i] = 'x';
	for (int i = 0; i < N; i++) { cin >> Map[i]; if (Map[i][0] == '?')idx = i; }

	for (int j = 0; j < M; j++) {
		int pos = j;
		for (int i = N - 1; i > idx; i--) {
			if (pos == 0 && Map[i][pos] == '-')pos++;
			else if (pos == M - 1 && Map[i][pos - 1] == '-')pos--;
			else {
				if (Map[i][pos - 1] == '-')pos--;
				else if (Map[i][pos] == '-')pos++;
			}
		}
		result[pos] = order[j];
	}
	for (int i = 0; i < M; i++)check(i);
	for (int i = 0; i < M - 1; i++)
	{
		if (result[i] == str[i])ladder[i] = '*';
		else if (result[i] == str[i + 1] || str[i] == result[i + 1]) { ladder[i] = '-'; swap(str[i], str[i + 1]); }
		else { cout << nope; return 0; }
	}
	cout << ladder;
}