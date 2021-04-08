#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int N;
bool Route[100][100];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) { int a; cin >> a; if (a == 1)Route[i][j] = true; }
	for (int k = 0; k < N; k++)for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)if (Route[i][k] && Route[k][j])Route[i][j] = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)(Route[i][j]) ? cout << "1 " : cout << "0 ";
		cout << "\n";
	}
	return 0;
}

