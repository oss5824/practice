#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
#define INF 987654321
using namespace std;
int N, K;
bool visit[1001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> K; int cnt = 0;
	for (int i = 2; i <= N; i++){
		for (int j = i; j <= N; j += i){
			if (visit[j])continue;
			visit[j] = true; cnt++;
			if (cnt == K) { cout << j; return 0; }
		}
	}
	return 0;
}

