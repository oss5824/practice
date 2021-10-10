#include <iostream>
#include <queue>
#include <set>
#include <cmath>
#define MAX pow(2,31)
using namespace std;
int n, k, idx, arr[100], val;
int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false); priority_queue<int>pq; set<int>s;
    cin >> k >> n;
    for (int i = 0; i < k; i++) { cin >> arr[i]; pq.push(-arr[i]); }
    while (idx < n) {
        val = -pq.top(); pq.pop(); 
        if (s.count(val))continue;
        idx++; s.insert(val);
        for (int i = 0; i < k; i++) {
            long long res = (long long)val * (long long)arr[i];
            if (res < MAX)pq.push(-res);
        }
    }cout << val;
}