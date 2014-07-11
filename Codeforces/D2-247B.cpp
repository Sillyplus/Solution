#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int q[10];
int a[10][10] = {0};
bool vt[10];
int ans = 0;

void check(int x) {
    if (x != 5) {
        for (int i = 1; i <= 5; i++) {
            if (!vt[i]) {
                vt[i] = true;
                q[x] = i;
                check(x+1);
                vt[i] = false;
            }
        }
    } else {
        int tmp = 0;
        tmp += a[q[0]][q[1]] + a[q[1]][q[0]] + a[q[1]][q[2]] + a[q[2]][q[1]];
        tmp += 2*(a[q[2]][q[3]] + a[q[3]][q[2]] + a[q[3]][q[4]] + a[q[4]][q[3]]);
        ans = max(ans, tmp);
    }
}

int main() {
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            cin >> a[i][j];
    memset(vt, false, sizeof(vt));
    check(0);
    cout << ans << endl;
    return 0;
}
