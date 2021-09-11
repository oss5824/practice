#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, len, maxlen;
string s, tmp;
string Map[4];
int dx[8] = { -1,-1,0,1,1,1,0,-1 }, dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int arrScore[9] = { 0,0,0,1,1,2,3,5,11 };
set<string>st;
bool visit[4][4];
struct Trie {
    Trie* node[26];
    bool fin;
    Trie() { fin = false; for (int i = 0; i < 26; i++)node[i] = NULL; }
    void insert(int idx) {
        if (idx == len) { fin = true; return; }
        int pos = s[idx] - 'A';
        if (node[pos] == NULL)node[pos] = new Trie();
        node[pos]->insert(idx + 1);
    }
    void find(int x, int y, int idx) {
        if (x < 0 || y < 0 || x >= 4 || y >= 4 || visit[y][x] || idx >= 8)return;
        
        int pos = Map[y][x] - 'A';
        if (node[pos] == NULL)return;
        tmp.push_back((char)(pos + 'A')); visit[y][x] = true;
        if (node[pos]->fin)st.insert(tmp);
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            node[pos]->find(nx, ny, idx + 1);
        }
        visit[y][x]=false;
        tmp.pop_back();
    }
};
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> n;
    Trie* node = new Trie();
    for (int i = 0; i < n; i++) {
        cin >> s; len = s.length(); node->insert(0); maxlen = max(maxlen, len);
    }
    cin >> m;
    for (int k = 0; k < m; k++) {
        st.clear(); 
        string res = "";
        int cnt = 0, score = 0;
        for (int j = 0; j < 4; j++)cin >> Map[j];
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++)node->find(j, i, 0);
        for (string str : st) {
            int sz = str.length();
            score += arrScore[sz];
            if (res.length() < sz)res = str;
        }cout << score << " " << res << " " << st.size() << "\n";
    }
}