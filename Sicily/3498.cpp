#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 10;

bool p[MAXN];
vector<int> v;

int main() {
    memset(p, true, sizeof(p));
    p[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if (p[i]) {
            v.push_back(i);
            for (int j = 2*i; j <= MAXN; j += i)
                p[j] = false;
            }
        }
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; n != 1; i++) {
            while (n && (!(n % v[i]))) {
                printf("%d ", v[i]);
                n = n / v[i];
            }
        }
        printf("\n");
    }
    return 0;
}
