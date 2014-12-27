/*******************************************************************************
	> File Name: 1837.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat Dec 27 20:54:39 2014
 ******************************************************************************/

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

const string winer = "Isenbaev";
const int MAXN = 310;

int n, src;
string s[3];
map<string, int> mp;
vector<int> adj[MAXN];
int ans[MAXN];
bool visit[MAXN];
queue<int> q;

int main() {
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[0] >> s[1] >> s[2];
        for (int j = 0; j < 3; j++) {
            if (mp.find(s[j]) == mp.end()) {
                mp[s[j]] = count++;
            }
        }
        for (int j = 0; j < 3; j++) {
            adj[mp[s[j]]].push_back(mp[s[(j+1) % 3]]);
            adj[mp[s[j]]].push_back(mp[s[(j+2) % 3]]);
        }
    }
    memset(visit, false, sizeof(visit));
    int deep = 0;
    if (mp.find(winer) != mp.end()) {
        src = mp[winer];
        visit[src] = true;
        ans[src] = deep;
        q.push(src);
    }
    q.push(-1);
    while (q.size() != 1) {
        deep++;
        while (q.front() != -1) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                if (!visit[adj[u][i]]) {
                    visit[adj[u][i]] = true;
                    ans[adj[u][i]] = deep;
                    q.push(adj[u][i]);
                }
            }
        }
        q.pop();
        q.push(-1);
    }
    map<string, int>::iterator its;
    for (its = mp.begin(); its != mp.end(); its++) {
        cout << its->first << " ";
        if ((its->first != winer) && (ans[its->second] == 0))
            cout << "undefined" << endl;
        else 
            cout << ans[its->second] << endl;
    }
    return 0;
}
