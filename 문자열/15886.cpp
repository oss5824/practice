#include <iostream>
#include <string>
using namespace std;
int N,i,cnt;
int main()
{
    cin >> N; 
    string s; cin >> s;
    for (; i < N - 1; i++) { if (s.substr(i, 2) == "EW")cnt++; }
    cout << cnt;
}