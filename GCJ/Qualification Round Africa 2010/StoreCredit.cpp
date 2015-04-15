#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int a[2010] = {0};
int b[1010][3] = {0};

int main() {
    int t, c, l, k, x = 0;
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        cin >> c >> l;
        bool flag = true;
        for (int i = 1; i <= l; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= l; i++){
            for (int j = i+1; j <= l; j++) {
                if (a[i] + a[j] == c) {
                    printf("Case #%d: %d %d\n", ++x, i, j);
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
    }
    return 0;
}
