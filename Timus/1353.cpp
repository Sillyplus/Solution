#include <iostream>
#include <cstring>

using namespace std;

int s;
int f[11][100];

int main() {
    memset(f, 0, sizeof(f));
    for (int i = 1; i < 10; i++)
        f[1][i] = 1;
    for (int i = 2; i < 10; i++) {
        for (int j = 1; j <= 81; j++) {
            for (int k = 0; k < 10; k++) {
                if (j > k) {
                    f[i][j] += f[i-1][j-k];
                }
            }
        }
    }
    f[10][1] = 1;
    cin >> s;
    int ans = 0;
    for (int i = 1; i <= 10; i++) {
        ans += f[i][s];
    }
    cout << ans << endl;
    return 0;
}
