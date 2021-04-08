#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
vector<string>v;
int n;
struct Node
{
	map<string, Node*>m;
	void Insert(int dep)
	{
		if (dep == n)return;
		string s = v[dep];
		auto pos = m.find(s);
		if (pos == m.end())
		{
			Node* node = new Node;
			m.insert({ s,node });
			node->Insert(dep + 1);
		}
		else pos->second->Insert(dep + 1);
	}
	void print(int dep)
	{
		if (m.empty())return;
		for (auto i : m)
		{
			for (int i = 0; i < dep; i++)cout << "--";
			cout << i.first << "\n";
			i.second->print(dep + 1);
		}
	}
};
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	Node* node = new Node; int T; cin >> T;
	for (int q = 0; q < T; q++)
	{
		cin >> n; string s; v.clear();
		for (int i = 0; i < n; i++) { cin >> s; v.push_back(s); }
		node->Insert(0);
	}
	node->print(0);
	return 0;
}
