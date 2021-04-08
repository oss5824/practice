#include<iostream>
#include<algorithm>
using namespace std;
int Map[501][501];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int N, M, result = 0;
	cin >> N >> M; 
	for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)cin >> Map[i][j];
	//긴거
	for (int j = 1; j <= N; j++) {
		for (int i = 1; i <= M - 3; i++) {
			int sum = 0;
			sum += Map[j][i] + Map[j][i + 1] + Map[j][i + 2] + Map[j][i + 3];
			result = max(sum, result);
		}
	}
	for (int j = 1; j <= N - 3; j++) {
		for (int i = 1; i <= M; i++) {
			int sum = 0;
			sum += Map[j][i] + Map[j + 1][i] + Map[j + 2][i] + Map[j + 3][i];
			result = max(sum, result);
		}
	}
	//네모난거
	for (int j = 1; j <= N - 1; j++) {
		for (int i = 1; i <= M - 1; i++) {
			int sum = 0;
			sum += Map[j][i] + Map[j][i + 1] + Map[j + 1][i] + Map[j + 1][i + 1];
			result = max(sum, result);
		}
	}
	//위로 긴 ㄱ자모양
	for (int j = N; j >= 3; j--) {
		for (int i = 1; i <= M - 1; i++) {
			int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
			sum1 += Map[j][i] + Map[j - 1][i] + Map[j - 2][i] + Map[j - 2][i + 1];
			sum2 += Map[j][i] + Map[j - 1][i] + Map[j - 2][i] + Map[j][i + 1];
			sum3 += Map[j][i + 1] + Map[j - 1][i + 1] + Map[j - 2][i + 1] + Map[j - 2][i];
			sum4 += Map[j][i + 1] + Map[j - 1][i + 1] + Map[j - 2][i + 1] + Map[j][i];
			result = max(sum1, result); result = max(sum2, result);
			result = max(sum3, result); result = max(sum4, result);
		}
	}
	//옆으로로 긴 ㄱ자모양
	for (int j = N; j >= 2; j--) {
		for (int i = 1; i <= M - 2; i++) {
			int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
			sum1 += Map[j - 1][i] + Map[j - 1][i + 1] + Map[j - 1][i + 2] + Map[j][i];
			sum2 += Map[j - 1][i] + Map[j - 1][i + 1] + Map[j - 1][i + 2] + Map[j][i + 2];
			sum3 += Map[j][i] + Map[j][i + 1] + Map[j][i + 2] + Map[j - 1][i];
			sum4 += Map[j][i] + Map[j][i + 1] + Map[j][i + 2] + Map[j - 1][i + 2];
			result = max(sum1, result); result = max(sum2, result);
			result = max(sum3, result); result = max(sum4, result);
		}
	}
	//초록색 위로
	for (int j = N; j >= 3; j--) {
		for (int i = 1; i <= M - 1; i++) {
			int sum1 = 0, sum2 = 0;
			sum1 += Map[j - 2][i] + Map[j - 1][i + 1] + Map[j - 1][i] + Map[j][i + 1];
			sum2 += Map[j][i] + Map[j - 1][i + 1] + Map[j - 1][i] + Map[j - 2][i + 1];
			result = max(sum1, result);	result = max(sum2, result);
		}
	}
	//초록색 눞혀서
	for (int j = N; j >= 2; j--) {
		for (int i = 1; i <= M - 2; i++) {
			int sum1 = 0, sum2 = 0;
			sum1 += Map[j][i] + Map[j - 1][i + 1] + Map[j - 1][i + 2] + Map[j][i + 1];
			sum2 += Map[j][i + 2] + Map[j - 1][i + 1] + Map[j - 1][i] + Map[j][i + 1];
			result = max(sum1, result);	result = max(sum2, result);
		}
	}
	//분홍색 위로
	for (int j = N; j >= 2; j--) {
		for (int i = 1; i <= M - 2; i++) {
			int sum1 = 0, sum2 = 0;
			sum1 += Map[j - 1][i + 2] + Map[j - 1][i + 1] + Map[j - 1][i] + Map[j][i + 1];
			sum2 += Map[j][i] + Map[j - 1][i + 1] + Map[j][i + 2] + Map[j][i + 1];
			result = max(sum1, result);	result = max(sum2, result);
		}
	}
	//분홍색 세워서
	for (int j = N; j >= 3; j--) {
		for (int i = 1; i <= M - 1; i++) {
			int sum1 = 0, sum2 = 0;
			sum1 += Map[j][i] + Map[j - 1][i + 1] + Map[j - 1][i] + Map[j - 2][i];
			sum2 += Map[j - 2][i + 1] + Map[j - 1][i + 1] + Map[j - 1][i] + Map[j][i + 1];
			result = max(sum1, result);	result = max(sum2, result);
		}
	}cout << result;
	return 0;
}