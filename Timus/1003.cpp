/*******************************************************************************
	> File Name: 1003.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Mon May 18 23:39:19 2015
*******************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>

using namespace std;

const int MAXN = 1e9 + 10;

map<int, int> father;

int find(int x) {
    return father[x] = (father[x] == x ? x : find(father[x]));
} 

void add(int x) {
    if (father.find(x) == father.end()) father[x] = x;
}

void merge(int l, int r) {
    father[find(l)] = find(r);
}

int main() {
    int n, m;
    while (scanf("%d", &n) == 1 && n != -1) {

        int l, r, ans = 0;
        string s;
        bool flag = true;
        father.clear();

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> l >> r >> s;
            if (l > r) swap(l , r);
            l--;
            add(l), add(r), add(l+MAXN), add(r+MAXN);
            if (flag) {
                if (s[0] == 'e') {
                    if (find(l) == find(r+MAXN) || find(l+MAXN) == find(r))
                        flag = false;
                    merge(l, r);
                    merge(l+MAXN, r+MAXN);
                } else {
                    if (find(l) == find(r) || find(l+MAXN) == find(r+MAXN))
                        flag = false;
                    merge(l, r+MAXN);
                    merge(l+MAXN, r);
                }  
                if (flag) ans++;
            } else {
                continue;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
