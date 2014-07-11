#include <iostream>
#include <cstring>

typedef long long LL;
using namespace std;

const int MN = 11;

LL c[MN][MN];
LL f[MN];

int main() {
    int n;
    for (int i = 0; i < MN; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
    }
    for (int i = 2; i < MN; i++) {
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }
    f[0] = f[1] = 1;
    for (int i = 2; i < MN; i++) {
        for (int j = 1; j <= i; j++) {
            f[i] += (c[i][j] * f[i-j]);
        }
    }
    cin >> n;
    while (n != -1) {
        cout << f[n] << endl;
        cin >> n;
    }
    return 0;
}
