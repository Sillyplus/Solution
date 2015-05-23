/*******************************************************************************
	> File Name: c.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sat May 23 07:12:31 2015
*******************************************************************************/

#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

const int MAXN = 15;

int n, k1, k2, a[MAXN], b[MAXN];
set<PLL> v;

PLL ha() {
    LL h1 = 0, h2 = 0;
    for (int i = 0; i < k1; i++)
        h1 = h1 * (n+1) + a[i];
    for (int i = 0; i < k2; i++)
        h2 = h2 * (n+1) + b[i];
    return PLL(h1, h2);
}

void pp(int x[MAXN], int &n) {
    for (int i = 0; i < n; i++)
        x[i] = x[i+1];
    n--;
}

int main() {
    cin >> n;
    cin >> k1;
    for (int i = 0; i < k1; i++)
        scanf("%d", a+i);
    cin >> k2;
    for (int i = 0; i < k2; i++)
        scanf("%d", b+i);
    int ans = 0;
    while (k1 > 0 && k2 >0) {
        PLL h = ha();
        if (v.find(h) != v.end()) {
            ans = -1;
            break;
        }
        v.insert(h);
        ans++;
        int atop = a[0], btop = b[0];
        pp(a, k1), pp(b, k2);
        if (atop > btop) {
            a[k1++] = btop;
            a[k1++] = atop;
        } else {
            b[k2++] = atop;
            b[k2++] = btop;
        }
    }
    cout << ans;
    if (ans > 0) {
        int win = k1 > 0 ? 1 : 2;
        printf(" %d\n", win);
    } else {
        printf("\n");
    }
    return 0;
}
