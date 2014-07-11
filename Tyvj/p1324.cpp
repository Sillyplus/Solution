#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MN = 200010;

int n, m;
int f[MN];
int a[MN];

inline int lowbit(int x) {
    return (x & -x);
}

void add(int x, int value) {
    for (int i = x; i < n+10 ; i += lowbit(i))
        f[i] += value;
}

int get(int x) {
    int sum = 0;
    for (int i = x; i; i -=lowbit(i))
        sum += f[i];
    return sum;
}

int main() {
    cin >> n;
    int x, l, r;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a[i+1] = x;
        add(i+1, x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &l, &r);
        x = get(r) - get(l-1);
        double ans;
        ans = 3.14 * x;
        printf("%.2f\n", ans);
        x = (l+r) / 2;
        add(x, -a[x]);
        a[x] = 0;
    }
    return 0;
}
