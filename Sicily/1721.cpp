#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MN = (1 << 16) + 10;

bool f[MN][20];

int main() {
    memset(f, false, sizeof(f));
    for (int i = 0; i < (1 << 16); i++) {
        int k = i;
        for (int j = 0; k; j++) {
            if (k % 2) f[i][j] = true;
            k /= 2;
        }
        for (int j = 0; j < 16; j++) {
            f[i][j] = f[i][j] ^ f[i][j+1];
        }
    }
    int x;
    cin >> x;
    while (x) {
        for (int i = 0; i < (1 << x); i++) {
            for (int j = x-1; j >= 0; j--) {
                if (f[i][j]) printf("1");
                    else printf("0");
            }
            printf("\n");
        }
        printf("\n");
        cin >> x;
    }
    return 0;
}
