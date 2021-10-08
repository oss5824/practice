#include <iostream>
using namespace std;
float cnt;
char v[100001][90];
struct Node
{
	Node* node[26];
	bool fin;
	int cntNode = 0;
	Node() { fin = false; for (int i = 0; i < 26; i++)node[i] = NULL; }
	~Node() { for (int i = 0; i < 26; i++)if (node[i] != NULL)delete node[i]; }
	void Insert(const char* str){
		if (*str == 0) { fin = true; return; }
		int cur = *str - 'a';
		if (node[cur] == NULL)cntNode++, node[cur] = new Node();
		node[cur]->Insert(str + 1);
	}
	void find(const char* str, int idx){
		if (*str == 0)return;
		int cur = *str - 'a';
		if (cntNode >= 2 || fin || idx == 0)cnt++;
		node[cur]->find(str + 1, idx + 1);
	}
};
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	int T;
	while (cin >> T){
		Node* node = new Node(); float result = 0;
		for (int i = 0; i < T; i++)cin >> v[i], node->Insert(v[i]);
		for (int i = 0; i < T; i++){ cnt = 0; node->find(v[i], 0); result += cnt; }
		printf("%.2f\n", result / T);
		delete node;
	}
}
