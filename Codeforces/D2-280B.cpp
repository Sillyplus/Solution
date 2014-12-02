#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1010;

int a[MAXN];

int main() {
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    int tmp = 0;
    for (int i = 1; i < n; i++)
        tmp = max(tmp, a[i]-a[i-1]);
    double ans = tmp*1.0;
    ans = max(ans/2, max(l-a[n-1], a[0]-0)*1.0);
    printf("%.10f\n", ans);
    return 0;
}
