#include<iostream>
using namespace std;
int main()
{
	int  start=1,arr[1001];
	for (int i = 1; start <= 1000; i++)for (int j = 1; j <= i && start <= 1000; j++, start++)arr[start] = i;
	int a, b; cin >> a >> b;
	int lsum = 0, rsum = 0; for (int i = 1; i < a; i++)lsum += arr[i]; for (int i = 1; i <= b; i++)rsum += arr[i];
	cout << rsum - lsum;
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
