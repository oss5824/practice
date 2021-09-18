#include <iostream>
using namespace std;
int A, B, C, arr[1000000];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin>>A;
	for (int i = 0; i < A; i++)cin >> arr[i];
	cin >> B >> C;
	unsigned long long result = 0;
	for (int i = 0; i < A; i++) {
		if (arr[i] <= B) { result++; }
		else {
			int remain = arr[i] - B; result++;
			result += (remain % C == 0) ? remain / C : remain / C + 1;
		}
	}cout << result;
}

//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);