#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MN = 100100;

int a[MN];
int n, m;

int main() {
    while ((scanf("%d%d", &n, &m) == 2) && (n != 0 && m != 0)) {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        int cnt = 0;
        printf("%d", a[cnt]);
        cnt += m;
        while (cnt < n) {
            printf(" %d", a[cnt]);
            cnt += m;
        }
        cout << endl;
    }
    return 0;
}
