#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
vector <pair<float, pair<int, int>>>d;
int level[101];
int arr[101];
float result;
int search(int num)
{
	if (num == arr[num])return num;
	else return arr[num] = search(arr[num]);
}
int add(pair<float, pair<int, int>>v)
{
	int a = v.second.first, b = v.second.second;
	float c = v.first;
	int x = search(a), y = search(b);
	if (x == y)return 1;
	if (level[x] > level[y]) { int tmp = x; x = y; y = tmp; }
	arr[x] = y, result += c;
	if (level[x] == level[y])level[y]++;
	return 0;
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<pair<float, float>>v;
	float f;
	for (int i = 0; i < n; i++)
	{
		float a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	int len = v.size(), cnt = 1;
	for (int i = 0; i < len; i++)
	{
		arr[i] = i;
		for (int j = i + 1; j < len; j++)
			d.push_back({ (float)sqrt(pow((v[i].first - v[j].first), 2.0) + pow((v[i].second - v[j].second), 2.0))
				, { i,j } });
	}
	sort(d.begin(), d.end());
	len = d.size();
	for (int i = 0; i < len; i++)add(d[i]);
	printf("%.2f", result);
	return 0;
}