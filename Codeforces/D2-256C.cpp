#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MN = 5010;

int n, a[MN];

int sol(int l, int r, int cut) {
    int sum, tmp = r-l+1;
    int mi = a[l], last = l;
    for (int i = l; i <= r; i++)
        mi = min(mi, a[i]);
    sum = mi-cut;
    for (int i = l; i <= r; i++)
        if (a[i] == mi) {
            if (last < i)
                sum += sol(last, i-1, mi);
            last = i+1;
        }
    if (last <= r)
        sum += sol(last, r, mi);
    return min(sum, tmp);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << sol(1, n, 0) << endl;
    return 0;
}
