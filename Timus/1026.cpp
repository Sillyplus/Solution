#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MN = 100010;

int n, k, x;
int a[MN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    string s;
    cin >> s;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        scanf("%d", &x);
        printf("%d\n", a[x]);
    }
    return 0;
}
