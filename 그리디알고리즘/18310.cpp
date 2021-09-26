#include<iostream>
#include<algorithm>
using namespace std;
int n,v[200000];
int main(){
	cin.tie(NULL);ios::sync_with_stdio(false);
	cin >> n;for (int i = 0; i < n; i++)cin >> v[i];
	sort(v, v + n); cout << v[(n - 1) / 2];
}
