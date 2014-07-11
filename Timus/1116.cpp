#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MN = 64010;
const int DL = 32000;

struct interval {
    int l, r;
    int fx;
};

interval f3[DL];
int f1[MN], f2[MN];
int n, m, l, r, y;

int main() {
    for (int i = 0; i < MN; i++) f1[i] = 1000;
    memset(f2, 0, sizeof(f2));

    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &l, &r, &y);
        for (int j = l+DL; j < r+DL; j++)
            f1[j] = y;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &l, &r, &y);
        for (int j = l+DL; j < r+DL; j++)
            f2[j] = 1;
    }

    int tot = 0;
    for (int i = 0; i < MN; i++) {
        if (f1[i] != 1000 && !f2[i]) {
            f3[tot].l = i - DL;
            f3[tot].fx = f1[i];
            while (f1[i] != 1000 && !f2[i] && f1[i] == f3[tot].fx) i++;
            f3[tot].r = i - DL;
            i--;
            tot++;
        }
    }

    cout << tot;
    for (int i = 0; i < tot; i++) {
        printf(" %d %d %d", f3[i].l, f3[i].r, f3[i].fx);
    }
    cout << endl;
    return 0;
}
