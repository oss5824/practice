#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int tree[4000000], n;
int querySub(int s, int e, int node, int val)
{
    tree[node]--;
    if (s == e) { return s; }
    int m = (s + e) / 2;
    if (val <= tree[2 * node])return querySub(s, m, 2 * node, val);
    else return querySub(m + 1, e, 2 * node + 1, val - tree[2 * node]);
}
void queryAdd(int s, int e, int node, int idx, int diff)
{
    if (idx<s || idx>e)return;
    tree[node] += diff;
    if (s != e) {
        int m = (s + e) / 2;
        queryAdd(s, m, 2 * node, idx, diff);
        queryAdd(m + 1, e, 2 * node + 1, idx, diff);
    }
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0, a, b; i < n; i++) {
        int query; cin >> query;
        if (query == 1) { cin >> a; cout << querySub(1, 1000000, 1, a) << "\n"; }
        else { cin >> a >> b; queryAdd(1, 1000000, 1, a, b); }
    }
}