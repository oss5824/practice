#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int arr[10][10], result = INF;
int size_type[6] = { 0,5,5,5,5,5 };
int one_count, cnt;
bool check(int j, int i, int sz)
{
	if (i + sz > 10 || j + sz > 10)return false;
	for (int y = i; y < i + sz; y++)for (int x = j; x < j + sz; x++) { if (arr[y][x] == 0)return false; arr[y][x] = 0; }
	return true;
}
int paper_count() { int sum = 0; for (int i = 1; i <= 5; i++)sum = sum + 5 - size_type[i]; return sum; }
void solve(int x, int y)
{
	if (result < paper_count())return;
	if (cnt == one_count) { result = min(result, paper_count());return; }
	for (int i = y; i < 10; i++){
		for (int j = x; j < 10; j++){
			if (arr[i][j] == 0)continue;
			for (int sz = 5; sz >= 1; sz--){
				if (size_type[sz] == 0)continue;
				int backUpArr[10][10];
				memcpy(backUpArr, arr, sizeof(arr));
				bool paper = check(j, i, sz);
				if (paper){
					size_type[sz]--;
					cnt += sz * sz;
					solve(j , i);
					cnt -= sz * sz;
					size_type[sz]++;
				}
				memcpy(arr, backUpArr, sizeof(arr));
			}
			return;
		}
		x = 0;
	}

}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	for (int i = 0; i < 10; i++)for (int j = 0; j < 10; j++) { cin >> arr[i][j]; if (arr[i][j] == 1)one_count++; }
	solve(0, 0);
	result == INF ? cout << "-1" : cout << result;
	return 0;
}


