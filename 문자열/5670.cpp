#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
float cnt;
struct Node
{
	Node* node[26];
	bool fin;
	Node() { fin = false; fill(node, node + 26, nullptr); }
	~Node() { for (int i = 0; i < 26; i++)if (node[i] != NULL)delete node[i]; }
	void Insert(char* str)
	{
		if (*str == '\0') { fin = true; return; }
		int cur = *str - 'a';
		if (node[cur] == NULL)node[cur] = new Node;
		node[cur]->Insert(str + 1);
	}
	bool find(char* str)
	{
		if (*str == '\0')
		{
			if (fin)return true;
			else return false;
		}
		int cur = *str - 'a', check = 0;
		if (node[cur] == NULL)return false;
		for (int i = 0; i < 26; i++)if (node[i] != NULL)check++;
		if (check != 1 || fin)cnt++;
		return node[cur]->find(str + 1);
	}
};
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	int T;
	while (cin >> T)
	{
		vector<string>v; Node* node = new Node;
		for (int i = 0; i < T; i++)
		{
			string s; cin >> s; v.push_back(s); char* p = (char*)s.c_str(); node->Insert(p);
		}
		float result = 0;
		for (auto i : v)
		{
			cnt = 0;
			int check = 0;
			for (int i = 0; i < 26; i++)if (node->node[i] != NULL)check++;
			char* p = (char*)i.c_str(); node->find(p);
			if (check == 1)cnt++;
			result += cnt;
		}
		printf("%.2f\n", result / T);
	}
	return 0;
}
