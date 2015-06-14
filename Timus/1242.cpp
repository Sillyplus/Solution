/*******************************************************************************
	> File Name: 1242.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon Jun 15 01:10:18 2015
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

struct villager{
    vector<int> parent;
    vector<int> child;
};

villager a[MAXN];
bool vis1[MAXN], vis2[MAXN], flag[MAXN];
vector<int> ans;

void s1(int x) {
    queue<int> q;
    vis1[x] = true;
    flag[x] = false;
    q.push(x);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (int i = 0; i < a[s].parent.size(); ++i) {
            if (vis1[a[s].parent[i]] == false) {
                vis1[a[s].parent[i]] == true;
                q.push(a[s].parent[i]);
                flag[a[s].parent[i]] = false;
            }
        }
    }
}

void s2(int x) {
    queue<int> q;
    vis2[x] = true;
    flag[x] = false;
    q.push(x);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (int i = 0; i < a[s].child.size(); ++i) {
            if (vis2[a[s].child[i]] == false) {
                vis2[a[s].child[i]] == true;
                q.push(a[s].child[i]);
                flag[a[s].child[i]] = false;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int n, x, y;
    cin >> n;
    while (scanf("%d %d", &x, &y) == 2) {
        a[x].parent.push_back(y);
        a[y].child.push_back(x);
    }
    string s;
    cin >> s;
    memset(vis1, false, sizeof(vis1));
    memset(vis2, false, sizeof(vis2));
    memset(flag, true, sizeof(flag));
    while (cin >> x) {
        s1(x);
        s2(x); 
    }
    for (int i = 1; i <= n; ++i) {
        if (flag[i]) ans.push_back(i);
    }
    if (ans.size() == 0) {
        cout << 0 << endl;
    } else {
        for (int i = 0; i < ans.size(); ++i) 
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
