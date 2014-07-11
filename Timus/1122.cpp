#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int f[8][8] = {0}, a[8][8] = {0}, b[4][4] = {0};
int dx[4][4], dy[4][4];

bool check() {
    int s = a[1][1];
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            if (a[i][j] != s) return false;
    return true;
}

void convert(int x, int y) {
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            a[x+dx[i][j]][y+dy[i][j]] = a[x+dx[i][j]][y+dy[i][j]] ^ b[i][j];
}

void get() {
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            a[i][j] = f[i][j];
}

int main() {
    char c;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= 3; i++) {
        dy[i][1] = dx[1][i] = -1;
        dy[i][2] = dx[2][i] = 0;
        dy[i][3] = dx[3][i] = 1;
    }
    
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++) {
            cin >> c;
            if (c == 'B') f[i][j] = 1;
        }

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++) {
            cin >> c;
            b[i][j] = c - '0';
        }
    int ans = 1 << 17, x, y;
    for (int i = 0; i < (1 << 16); i++) {
        get();
        int tmp = 0, k = i, bit = 1;
        while (k) {
            while (k % 2 == 0) {
                bit++;
                k /= 2;
            }
            x = (bit-1)/4 + 1;
            y = (bit % 4 == 0) ? 4 : bit%4;
            convert(x, y);
            tmp++;
            bit++;
            k /= 2;
        }
        if (check()) ans = min(ans, tmp);
    }
    if (ans < (1 << 17)) cout << ans << endl;
        else cout << "Impossible" << endl;
    return 0;
}
