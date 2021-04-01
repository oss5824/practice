#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
#define INF 987654321
using namespace std;
int N, sum;
bool Map[100][100];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	while (N--) {
		int a, b; cin >> a >> b;
		for (int i = b; i < b + 10; i++)for (int j = a; j < a + 10; j++)Map[i][j] = true;
	}
	for (int i = 0; i < 100; i++)for (int j = 0; j < 100; j++)if (Map[i][j])sum++;
	cout << sum;
	return 0;
}

