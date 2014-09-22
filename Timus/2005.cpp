#include <iostream>
#include <cmath>

using namespace std;

int a[10][10];
int b[10];

int main() {
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            cin >> a[i][j];
    b[1] = 1;
    b[5] = 5;
    int ans = 2147483647;
    if (a[1][2]+a[2][3]+a[3][4]+a[4][5] < ans) {
        b[2] = 2;
        b[3] = 3;
        b[4] = 4;
        ans = a[1][2]+a[2][3]+a[3][4]+a[4][5];
    }
    if (a[1][3]+a[3][2]+a[2][4]+a[4][5] < ans) {
        b[2] = 3;
        b[3] = 2;
        b[4] = 4;
        ans = a[1][3]+a[3][2]+a[2][4]+a[4][5];
    }
    if (a[1][3]+a[3][4]+a[4][2]+a[2][5] < ans) {
        b[2] = 3;
        b[3] = 4;
        b[4] = 2;
        ans = a[1][3]+a[3][4]+a[4][2]+a[2][5];
    }
    if (a[1][4]+a[4][3]+a[3][2]+a[2][5] < ans) {
        b[2] = 4;
        b[3] = 3;
        b[4] = 2;
        ans = a[1][4]+a[4][3]+a[3][2]+a[2][5];
    }
    cout << ans << endl;
    for (int i = 1; i <= 5; i++)
        cout << b[i] << ' ';
    cout << endl;
    return 0;
}
