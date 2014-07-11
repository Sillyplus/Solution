#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MN = 20010;

int a[MN], b[MN];

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) == 2 && n && m) {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < m; i++)
            scanf("%d", &b[i]);
        sort(a, a+n);
        sort(b, b+m);
        int no = 0;
        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (b[i] >= a[no]) {
                ans += b[i];
                if (++no == n) break;
            }
        }
        if (no < n)
            printf("Loowater is doomed!\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
