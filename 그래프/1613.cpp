#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;

int N, K, S;
bool Map[401][401];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> K; int a, b;
	for (int i = 0; i < K; i++){
		cin >> a >> b;
		Map[a][b] = true;
	}
	cin >> S;
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (Map[i][k] && Map[k][j])Map[i][j] = true;
	while (S--){
		cin >> a >> b;
		if (Map[a][b])cout << "-1\n";
		else if (Map[b][a])cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}