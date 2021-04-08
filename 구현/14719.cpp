#include<iostream>
using namespace std;
int arr[502][502];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int h, w, a, sum = 0; cin >> h >> w;
	for (int i = 1; i <= w; i++) { cin >> a; for (int j = 1; j <= a; j++)arr[j][i] = 1; }
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w;)
			if (arr[i][j] == 1)
			{
				int val = 0; j++;
				while (arr[i][j] == 0 && j <= w) { j++; val++; }
				if (arr[i][j] == 1)sum += val;
			}
			else j++;
	cout << sum;
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);