#include <iostream>
#include <cmath>

using namespace std;

int k, h;
int f[10010][1010];

int main() {
    cin >> k >> h;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= h; j++) {
            f[i][j] = f[i][j-1] + f[i-1][j-1] + 1;
        }
    }
    for (int i = 1; i <= h; i++)
        if ( f[k][i] >= h) {
            cout << i << endl;
            return 0;
        }
    return 0;
}
