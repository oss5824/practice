#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<pair<int, int>>v;
bool cmp(pair<int, int>a, pair<int, int>b){
    return a.second < b.second;
}
int stringToTime(string s)
{
    string t = s.substr(0, 2);
    int time = stoi(t) * 60 + stoi(s.substr(3, 2));
    return time;
}
string timeToString(string s) { if (s.length() == 1)return ("0" + s); else return s; }
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        string s, team, time; getline(cin, s);
        istringstream str(s);
        getline(str, team, ' '); getline(str, time, ' ');
        v.push_back({ stoi(team),stringToTime(time) });
    }
    sort(v.begin(), v.end(), cmp);
    int team1 = 0, team2 = 0, team1Time = 0, team2Time = 0, beforeTime = 0;
    for (int i = 0; i < N; i++)
    {
        if (team1 == team2) {
            if (v[i].first == 1)team1++; else team2++;
        }
        else {
            if (team1 > team2)
                team1Time = team1Time + v[i].second - beforeTime;
            else team2Time = team2Time + v[i].second - beforeTime;
            if (v[i].first == 1)team1++; else team2++;
        }
        beforeTime = v[i].second;
    }
    if (team1 > team2) {
        team1Time = team1Time + 60 * 48 - v[N - 1].second;
    }
    else if (team1 < team2) {
        team2Time = team2Time + 60 * 48 - v[N - 1].second;
    }
    cout << timeToString(to_string(team1Time / 60))
        << ":" << timeToString(to_string(team1Time % 60)) << "\n";
    cout << timeToString(to_string(team2Time / 60)) << ":"
        << timeToString(to_string(team2Time % 60)) << "\n";
    return 0;
}