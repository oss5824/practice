#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, k;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> k;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    vector<int>res;
    for (int i = 1, a; i <= n; i++) {
        cin >> a; q.push({ a,i });
        while (1) {
            int value = q.top().first, index = q.top().second;
            if (i - k + 1 <= index && index <= i) {
                res.push_back(value);
                break;
            }
            else q.pop();
        }
    }
    for (int i : res)cout << i << " ";
}