#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct t{
    int l, r;
} a[500010];

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i= 1; i <= n+1; i++) {
            a[i].l = i-1;
            a[i].r = i+1;
        }
        int k, x, y;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &k, &x, &y);
            a[a[x].l].r = a[x].r;
            a[a[x].r].l = a[x].l;
            if (k == 1) {
                a[a[y].l].r = x;
                a[x].l = a[y].l;
                a[x].r = y;
                a[y].l = x;
            } else {
                a[a[y].r].l = x;
                a[x].r = a[y].r;
                a[x].l = y;
                a[y].r = x;
            }
        }
        int head = 0;
        /*
        for (int i = 0; i <= n; i++) {
            cout << a[i].l << ' ' << a[i].r << endl;
        }
        */
        while (a[head].r != n+1) {
            cout << a[head].r << ' ';
            head = a[head].r;
        }
        cout << endl;
    }
    return 0;
}
