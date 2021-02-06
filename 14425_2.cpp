#include <iostream>
using namespace std;
struct Node
{
	Node* node[26];
	bool fin;
	Node() { fin = false; fill(node, node + 26, nullptr); }
	void Insert(char* str)
	{
		if (*str == '\0') { fin = true; return; }
		int idx = *str - 'a';
		if (!node[idx])node[idx] = new Node;
		node[idx]->Insert(str + 1);
	}
	bool find(char* str)
	{
		int idx = *str - 'a';
		if (*str == '\0')
		{
			if (fin)return true;
			else return false;
		}
		if (node[idx] == NULL)return false;
		return node[idx]->find(str + 1);
	}
};
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, res = 0; 
	cin >> n >> m; Node* node = new Node();
	for (int i = 0; i < n; i++) { char str[501]; cin >> str; node->Insert(str); }
	for (int i = 0; i < m; i++) { char str[501]; cin >> str; if (node->find(str))res++; }
	cout << res;
	return 0;
}
