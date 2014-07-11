#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

const int MN = 130010;

struct arr{
    int w, pos;
};

arr a[MN];

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

bool comp1(const arr &a, const arr &b) {
    return a.w > b.w;
}

bool comp2(const arr &a, const arr &b) {
    return a.w < b.w;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].w);
        a[i].pos = i;
    }

    sort(a, a+n, comp1);
    int ans1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].pos == i) continue;
        if (ans1 == 0) {
            ans1 = abs(a[i].pos - i);
        } else {
            ans1 = gcd(ans1, abs(a[i].pos - i));
        }
    }
    sort(a, a+n, comp2);
    int ans2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].pos == i) continue;
        if (ans2 == 0) {
            ans2 = abs(a[i].pos - i);
        } else {
            ans2 = gcd(ans2, abs(a[i].pos - i));
        }
    }
    if (ans1 == 0 || ans2 == 0) {
        cout << n-1 << endl;
    } else {
        cout << max(ans1-1, ans2-1) << endl;
    }
    return 0;
}
