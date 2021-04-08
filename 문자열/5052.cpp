#include <iostream>
#include <string>
using namespace std;
bool check = false;
struct Node {
	Node* node[10];
	bool fin = false;
	Node() { fill(node, node + 10, nullptr); }
	void insert(char *str)
	{
		if (fin == true)check = true;
		if (*str == '\0' || *str == '\n') { fin = true; for (int i = 0; i < 10; i++)if (node[i] != nullptr)check = true; return; }
		int idx = *str - '0';
		if (node[idx] == NULL)node[idx] = new Node();
		node[idx]->insert(str + 1);
	}
};
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int t, n; cin >> t;
	while (t--) {
		cin >> n; cin.ignore(); Node* node = new Node(); check = false;
		for (int i = 0; i < n; i++) { string s; getline(cin, s); char* str = (char*)s.c_str(); node->insert(str); }
		if (check)cout << "NO\n"; else cout << "YES\n";
	}
	return 0;
}