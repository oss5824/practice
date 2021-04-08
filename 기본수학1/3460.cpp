#include<iostream>
#include<bitset>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); 
	int T, n; cin >> T;
	while (T--) {
		cin >> n;
		bitset<32>bit(n);
		for (int i = 0; i < 32; i++)if (bit[i] == 1)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
