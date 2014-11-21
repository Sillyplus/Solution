/*******************************************************************************
	> File Name: 12259.cpp
	> Author: sillyplus
	> Mail: oi_boy@sina.cn
	> Created Time: Wed Nov 19 19:08:37 2014
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 1010;

int fw[MAXN];
set<int> s;

bool check(int x) {
    bool ret;
    s.clear();
    while (true) {
        if (s.find(x) != s.end()) {
            ret = true;
            break;
        }
        if (fw[x] == 0) {
            ret = false;
            break;
        } else {
            s.insert(x);
            x = fw[x];
        }
    }
    return ret;
}

int main() {
    int n, ans = 0, k;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> fw[i];
    }
    for (int i = 1; i <= n; i++) {
        if (!check(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}
