#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
char *T, P[1000001], token[100001];
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	T = new char[1000001];
	cin.getline(T, 1000001); 
	cin.getline(P, sizeof(P));
	int len_T = strlen(T), len_P = strlen(P), len = len_T - len_P + 1;
	vector<int>v;
	for (int i = 0; i < len; i++, T++)
	{
		strncpy(token, T, len_P);
		if (!strcmp(token, P)) v.push_back(i + 1);
	}
	len = v.size();
	cout << len << "\n";
	for (int i = 0; i < len; i++)cout << v[i] << " ";
	return 0;
}