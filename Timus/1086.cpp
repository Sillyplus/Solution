#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MN = 200010;

bool valid[MN];
int f[MN];
int tot = 0;

void getPrime() {
    memset(valid, true, sizeof(valid));
    for (int i = 2; i <= MN; i++) {
        if (valid[i]) f[++tot] = i;
        for (int j = 1; (j <= tot) && (i*f[j] <= MN); j++) {
            valid[i*f[j]] = false;
            if (i % f[j] == 0) break;
        }
    }
}

int main() {
    getPrime();
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        printf("%d\n", f[x]);
    }
    return 0;
}
