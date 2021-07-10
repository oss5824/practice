#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, arr[100000];
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N; vector<int>v;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (v.empty() || v.back() < arr[i])v.push_back(arr[i]);
        else {
            int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[idx] = arr[i];
        }
    }
    cout << N - v.size();
}