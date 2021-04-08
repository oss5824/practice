#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
#define INF 987654321
using namespace std;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int a[5];
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
	while (1) {
		bool check = true;
		for (int i = 0; i < 4; i++)
		{
			if (a[i] < a[i + 1])continue;
			swap(a[i], a[i + 1]);
			for (int i = 0; i < 5; i++)cout << a[i] << " ";
			cout << "\n";
			check = false;
		}
		if (check)break;
	}
	return 0;
}

