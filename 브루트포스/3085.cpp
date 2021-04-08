#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[51][51], ch2[51][51];
int n, M;
void check()
{
	for (int i = 0; i < n; i++){
		char c = ch[i][0]; int m = 0;
		for (int j = 0; j < n; j++){
			if (c == ch[i][j]) m++;
			else {  M = max(m, M); c = ch[i][j]; m = 1; }
		}M = max(m, M);
	}
	for (int i = 0; i < n; i++) {
		char c = ch[0][i]; int m = 0;
		for (int j = 0; j < n; j++) {
			if (c == ch[j][i]) m++;
			else { M = max(m, M); c = ch[j][i]; m = 1; }
		}M = max(m, M);
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n; for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> ch2[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n-1; j++){
			memcpy(ch, ch2, sizeof(ch2));
			swap(ch[i][j], ch[i][j + 1]); check();
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++) {
			memcpy(ch, ch2, sizeof(ch2));
			swap(ch[j][i], ch[j + 1][i]);check();
		}
	cout << M;
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);