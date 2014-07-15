#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int MN = 100100;

int a[MN];
int fa[MN], fb[MN];
int n, ans;

int main() {
    cin >> n;
    memset(a, 0, sizeof(a));
    memset(fa, 0, sizeof(fa));
    memset(fb, 0, sizeof(fb));
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ans = 0;
    a[n+1] = 1000000010;
    a[0] = -1;
    fa[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > a[i-1])
            fa[i] = fa[i-1] + 1;
        else
            fa[i] = 1;
        ans = max(ans, fa[i]);
    }
    if (ans < n) ans++;
    for (int i = n; i >= 1; i--)
        if (a[i] < a[i+1])
            fb[i] = fb[i+1] + 1;
        else
            fb[i] = 1;
    fb[n+1] = 0;
    for (int i = 2; i <= n; i++) {
        if ((a[i+1] - a[i-1]) > 1) {
            ans = max(ans, fa[i-1] + fb[i+1] + 1);
        }
    }
    cout << ans << endl;
    return 0;
}
