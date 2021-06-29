#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int A1, B1, A2, B2;
set<pair<int, int>>visit;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> A1 >> B1 >> A2 >> B2;

    queue<pair<pair<int, int>, int>>q; q.push({ {0,0},0 }); visit.insert({ 0,0 });
    while (!q.empty()) {
        int curA = q.front().first.first, curB = q.front().first.second, curD = q.front().second; q.pop();
        if (curA == A2 && curB == B2) { cout << curD; return 0; }
        if (visit.count({ 0,curB }) == 0) { visit.insert({0,curB}); q.push({ {0,curB},curD + 1 }); }
        if (visit.count({ curA,0 }) == 0) { visit.insert({ curA,0 }); q.push({ {curA,0},curD + 1 }); }
        if (visit.count({ A1,curB }) == 0) { visit.insert({ A1,curB }); q.push({ {A1,curB},curD + 1 }); }
        if (visit.count({ curA,B1 }) == 0) { visit.insert({ curA,B1 }); q.push({ {curA,B1},curD + 1 }); }
        int nextA, nextB = curB + curA;
        if (B1 < nextB) {
            nextA = curA - (B1 - curB); nextB = B1;
            if (visit.count({ nextA,nextB }) == 0) { visit.insert({ nextA,nextB }); q.push({ {nextA,nextB},curD + 1 }); }
        }
        else {
            if (visit.count({ 0,nextB }) == 0) { visit.insert({ 0,nextB }); q.push({ {0,nextB},curD + 1 }); }
        }
        nextA = curB + curA;
        if (A1 < nextA) {
            nextA = A1; nextB = curB - (A1 - curA);
            if (visit.count({ nextA,nextB }) == 0) { visit.insert({ nextA,nextB }); q.push({ {nextA,nextB},curD + 1 }); }
        }
        else {
            if (visit.count({ nextA,0 }) == 0) { visit.insert({ nextA,0 }); q.push({ {nextA,0},curD + 1 }); }
        }
    }
    cout << "-1";
}