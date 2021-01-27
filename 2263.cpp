#include <iostream>
using namespace std;
int n, in[100001], post[100001], idx[100001];
void pre(int in_s, int in_e, int post_s, int post_e)
{
	if (in_s > in_e || post_s > post_e)return;
	int root = post[post_e], index = idx[root], len = index - in_s;
	cout << root << " ";
	pre(in_s, index - 1, post_s, post_s + len - 1);
	pre(index + 1, in_e, post_s + len, post_e - 1);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> in[i]; idx[in[i]] = i; }
	for (int i = 0; i < n; i++)cin >> post[i];
	pre(0, n - 1, 0, n - 1);
	return 0;
}