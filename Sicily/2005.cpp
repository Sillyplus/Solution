#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int v[10010];

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        memset(v, 0, sizeof(v));
        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        sort(v, v+n);
        int ct = 1;
        for (int i = 1; i <= n; i++) {
            if (v[i] == v[i-1]) {
                ct++;
            } else {
                if ((ct % 2) != 0) {
                    cout << v[i-1] << endl;
                    break;
                } else {
                    ct = 1;
                }
            }
        }
    }
    return 0;
}
